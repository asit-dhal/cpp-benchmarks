package main

import (
	"fmt"
	"flag"
	"bufio"
    "io"
    "log"
    "os"
    "encoding/csv"
    "io/ioutil"
    "strings"
    "strconv"
    "bytes"
)



func processArgs() (string, string) {
	ipFileNamePtr := flag.String("ip", "", "input csv filename")
	opFileNamePtr := flag.String("op", "", "output csv filename")
	flag.Parse()
	return *ipFileNamePtr, *opFileNamePtr
}

type TimeUnit int

const (
	NANO_SEC TimeUnit = 1 + iota
 	MICRO_SEC
 	MILI_SEC
 	SEC
 	NONE
)


type Benchmark struct {
	Name string `json:"name"`
	Operations int64 `json:"op_cnt"`
	CpuTime float64 `json:"cpu_time"`
	RealTime float64 `json:"real_time"`
	TimeType TimeUnit  `json:"time_unit"`
}

type Benchmarks []Benchmark 

func toTimeUnit(str string) TimeUnit {
	if str == "ns" {
		return NANO_SEC
	} else {
		return NONE
	}
}

func loadBenchmarks(fileName string) (Benchmarks, error) {
	csvFile, _ := os.Open(fileName)
    reader := csv.NewReader(bufio.NewReader(csvFile))
    var bms Benchmarks
    firstLine := true
    for {


        line, err := reader.Read()
        if err == io.EOF {
            break
        } else if err != nil {
            return nil, err
        }

        //first line is the header
        if firstLine == true {
    		firstLine = false
    		continue
    	}
        
        nameStr := strings.Split(line[0], "/") 
        name := strings.TrimSpace(nameStr[0])
        opCnt, err :=  strconv.ParseInt(nameStr[1], 10, 64)
        if err != nil {
        	return nil, err
        }

        realTime, err := strconv.ParseFloat(line[2], 64)
        if err != nil {
        	return nil, err
        }

        cpuTime, err := strconv.ParseFloat(line[3], 64)
		if err != nil {
        	return nil, err
        }        

        bms = append(bms, Benchmark{
            Name: name,
            Operations: opCnt,
          	RealTime: realTime/1000,
            CpuTime: cpuTime/1000,
            TimeType: MICRO_SEC, //toTimeUnit(line[4]),
        })
    }

    return bms, nil
}

func genMarkdown(opFileName string, bms Benchmarks) error {
	benchmarkNames := make([]string, 0)

	findBMName := func(nm string) bool {
		for _, name := range benchmarkNames {
			if name == nm {
				return true
			}
		}
		return false
	} 

	for _, rec := range bms {
		name := rec.Name
		if !findBMName(name) {
			benchmarkNames = append(benchmarkNames, name)
		}
	}

	opCnts := make([]int64, 0)
	
	findOpCnts := func(cnt int64) bool {
		for _, count := range opCnts {
			if count == cnt {
				return true
			}
		}
		return false
	} 

	for _, rec := range bms {
		opcnt := rec.Operations
		if !findOpCnts(opcnt) {
			opCnts = append(opCnts, opcnt)
		}
	}

	
	// print header
	var buffer bytes.Buffer	
	// print table header
	buffer.WriteString("#### ")
	buffer.WriteString(strings.Join(benchmarkNames[:]," vs "))
	buffer.WriteString("\n\n")	

	firstTable := true
	for _, benchmarkName := range benchmarkNames {
		var str string
		if firstTable {
			str = fmt.Sprintf("| Operation Count | %s ",  benchmarkName)
			firstTable = false
		} else {
			str = fmt.Sprintf("| %s ",  benchmarkName)
		}
		buffer.WriteString(str)
	}
	buffer.WriteString("|\n")	

	firstTable = true
	for _ = range benchmarkNames {
		if firstTable {
			buffer.WriteString("| ---- | ---- ")	
			firstTable = false
		} else {
			buffer.WriteString("| ---- ")	
		}
	}
	buffer.WriteString("|\n")	

	for _, opCnt := range opCnts {
		firstFlg := true
		for _, rec := range bms {
			if rec.Operations == opCnt {
				var str string
				if firstFlg {
					str = fmt.Sprintf("| %d | %.2f μs", opCnt, rec.RealTime)
					firstFlg = false
				} else {
					str = fmt.Sprintf("|%.2f μs", rec.RealTime)
				}

				buffer.WriteString(str)
			}
		}
		buffer.WriteString("|\n")
	}

	ioutil.WriteFile(opFileName, []byte(buffer.String()), 0644)

	return nil
}



func main() {
	ipFileName, opFileName := processArgs()
	fmt.Println("ipFileName: ", ipFileName)
	fmt.Println("opFileName: ", opFileName)
	bms, err := loadBenchmarks(ipFileName)
	if err != nil {
		log.Fatal(err)
	}

	err = genMarkdown(opFileName, bms)
	if err != nil {
		log.Fatal(err)
	}
}