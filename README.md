## Benchmarks

| test | fast | dummy |
|-|-|-|
|getUser| 5325645800 ns | 32603500 ns |
|addFriend| 19117600 ns | 16230500 ns |

| findUsers | fast | dummy |
|-|-|-|
| no filters, no sort, limit=2| 29100 ns | 1084 ms |
| no filters, no sort, limit=32| 23300 ns | 1051 ms |
| no filters, no sort, limit=512| 141300 ns | 1053 ms |
| no filters, no sort, limit=8192| 1923800 ns | 1052 ms |
| no filters, no sort, limit=131072| 25361800 ns | 85 ms |
| with age and city filters, no sort, limit=2| 85 ms | 1205 ms |
| with age and city filters, no sort, limit=32| 87 ms | 1223 ms |
| with age and city filters, no sort, limit=512| 84 ms | 1212 ms |
| with age and city filters, no sort, limit=8192| 85 ms | 1208 ms |
| with age and city filters, no sort, limit=131072| 94 ms | 1209 ms |
| with age and city filters, no sort, limit=2| 96 ms | 1215 ms |
| with age and city filters, no sort, limit=32| 86 ms | 1207 ms |
| with age and city filters, no sort, limit=512| 87 ms | 1196 ms |
| with age and city filters, no sort, limit=8192| 85 ms | 1218 ms |
| with age and city filters, no sort, limit=131072| 90 ms | 1237 ms |
| with age and city filters, name sort, limit=2| 115 ms | 2903 ms |
| with age and city filters, name sort, limit=32| 116 ms | 2948 ms |
| with age and city filters, name sort, limit=512| 116 ms | 2930 ms |
| with age and city filters, name sort, limit=8192| 117 ms | 2913 ms |
| with age and city filters, name sort, limit=131072| 124 ms | 3003 ms |
| with age and city filters, relevance sort, limit=2| 1941 ms | - |
| with age and city filters, relevance sort, limit=32| 1955 ms | - |
| with age and city filters, relevance sort, limit=512| 1988 ms | - |
| with age and city filters, relevance sort, limit=8192| 1982 ms | - |
| with age and city filters, relevance sort, limit=131072| 1993 ms | - |
| high selective name, gender filter, no sort, limit=2| 10 ms | 1045 ms |
| high selective name, gender filter, no sort, limit=32| 10 ms | 1027 ms |
| high selective name, gender filter, no sort, limit=512| 10 ms | 1026 ms |
| high selective name, gender filter, no sort, limit=8192| 9 ms | 1031 ms |
| high selective name, gender filter, no sort, limit=131072| 8 ms | 1045 ms |
| high selective with age, city and gender filters, no sort, limit=2 | 24 ms | 1050 ms |
| high selective with age, city and gender filters, no sort, limit=32 | 23 ms | 1089 ms |
| high selective with age, city and gender filters, no sort, limit=512 | 23 ms | 1043 ms |
| high selective with age, city and gender filters, no sort, limit=8192 | 23 ms | 1036 ms |
| high selective with age, city and gender filters, no sort, limit=131072 | 23 ms | 1054 ms |
| high selective with age and city filters, name sort, limit=2 | 13 ms | 1146 ms |
| high selective with age and city filters, name sort, limit=32 | 13 ms | 1137 ms |
| high selective with age and city filters, name sort, limit=512 | 12 ms | 1139 ms |
| high selective with age and city filters, name sort, limit=8192| 12 ms | 1126 ms |
| high selective with age and city filters, name sort, limit=131072| 17 ms | 1162 ms |
| high selective with age and city filters, relevance sort, limit=2| 108 ms | 67575 ms |
| high selective with age and city filters, relevance sort, limit=32| 104 ms | 67908 ms |
| high selective with age and city filters, relevance sort, limit=512| 114 ms | 68043 ms |
| high selective with age and city filters, relevance sort, limit=8192| 109 ms | 68241 ms |
| high selective with age and city filters, relevance sort, limit=131072| 118 ms | 57296 ms |
