
#### Bool_ToString vs Bool_StringStream vs Bool_OstringStream

| Operation Count | Bool_ToString | Bool_StringStream | Bool_OstringStream |
| ---- | ---- | ---- | ---- |
| 8 | 1.10 μs|0.85 μs|0.94 μs|
| 16 | 2.00 μs|1.28 μs|1.42 μs|
| 32 | 3.80 μs|2.03 μs|2.04 μs|
| 64 | 7.33 μs|3.55 μs|3.39 μs|
| 128 | 14.08 μs|6.67 μs|6.23 μs|
| 256 | 27.66 μs|13.19 μs|12.83 μs|
| 512 | 54.70 μs|25.80 μs|25.07 μs|
| 10000000 | 1058870.00 μs|514314.00 μs|458134.00 μs|


#### Double_ToString vs Double_StringStream vs Double_OstringStream

| Operation Count | Double_ToString | Double_StringStream | Double_OstringStream |
| ---- | ---- | ---- | ---- |
| 8 | 4.88 μs|7.69 μs|7.25 μs|
| 16 | 10.57 μs|16.20 μs|15.53 μs|
| 32 | 26.24 μs|32.03 μs|31.66 μs|
| 64 | 52.25 μs|62.22 μs|62.27 μs|
| 128 | 107.70 μs|113.32 μs|113.45 μs|
| 256 | 205.99 μs|235.57 μs|235.54 μs|
| 512 | 397.08 μs|478.61 μs|478.17 μs|
| 10000000 | 10830000.00 μs|12918800.00 μs|12544400.00 μs|


#### Int_ToString vs Int_StringStream vs Int_OstringStream

| Operation Count | Int_ToString | Int_StringStream | Int_OstringStream |
| ---- | ---- | ---- | ---- |
| 8 | 1.09 μs|0.89 μs|1.09 μs|
| 16 | 2.40 μs|1.54 μs|1.75 μs|
| 32 | 4.68 μs|2.44 μs|3.19 μs|
| 64 | 9.12 μs|5.68 μs|5.84 μs|
| 128 | 17.85 μs|10.28 μs|10.55 μs|
| 256 | 31.71 μs|19.83 μs|18.65 μs|
| 512 | 62.91 μs|36.70 μs|35.16 μs|
| 10000000 | 1386700.00 μs|848892.00 μs|841556.00 μs|


#### Mixed_ToString vs Mixed_StringStream vs Mixed_OstringStream

| Operation Count | Mixed_ToString | Mixed_StringStream | Mixed_OstringStream |
| ---- | ---- | ---- | ---- |
| 8 | 7.74 μs|8.23 μs|7.23 μs|
| 16 | 14.64 μs|15.23 μs|13.37 μs|
| 32 | 26.10 μs|32.42 μs|27.00 μs|
| 64 | 50.83 μs|80.83 μs|57.77 μs|
| 128 | 102.08 μs|157.14 μs|112.30 μs|
| 256 | 198.93 μs|306.28 μs|230.96 μs|
| 512 | 437.89 μs|611.76 μs|454.67 μs|
| 10000000 | 8367480.00 μs|9443050.00 μs|11741500.00 μs|


#### SmallString_ToString vs SmallString_StringStream vs SmallString_OstringStream vs LargeString_ToString vs LargeString_StringStream vs LargeString_OstringStream

| Operation Count | SmallString_ToString | SmallString_StringStream | SmallString_OstringStream | LargeString_ToString | LargeString_StringStream | LargeString_OstringStream |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 8 | 0.71 μs|0.95 μs|1.17 μs|1.37 μs|1.79 μs|1.50 μs|
| 16 | 1.31 μs|1.13 μs|1.43 μs|1.70 μs|3.23 μs|2.44 μs|
| 32 | 1.28 μs|1.71 μs|1.74 μs|3.22 μs|5.25 μs|4.11 μs|
| 64 | 1.80 μs|2.54 μs|2.71 μs|6.20 μs|9.90 μs|9.19 μs|
| 128 | 2.84 μs|6.34 μs|4.90 μs|12.28 μs|18.87 μs|18.56 μs|
| 256 | 4.98 μs|12.74 μs|12.90 μs|24.33 μs|41.66 μs|46.14 μs|
| 512 | 9.35 μs|24.39 μs|20.87 μs|56.97 μs|95.26 μs|93.72 μs|
| 10000000 | 160303.00 μs|452659.00 μs|404348.00 μs|
| 1000000 | 438377.00 μs|756111.00 μs|1008580.00 μs|


#### VectorInsert vs VectorInsertWithReserve vs ArrayInsert vs VectorSort vs ArraySort

| Operation Count | VectorInsert | VectorInsertWithReserve | ArrayInsert | VectorSort | ArraySort |
| ---- | ---- | ---- | ---- | ---- | ---- |
| 200 | 2.21 μs|1.05 μs|0.00 μs|2.10 μs|2.05 μs|


