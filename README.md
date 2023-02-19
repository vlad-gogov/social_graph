## Benchmarks

| test | fast | dummy |
|-|-|-|
|getUser|  ns | 32603500 ns |
|addFriend|  ns | 16230500 ns |

| findUsers | fast | dummy |
|-|-|-|
| no filters, no sort, limit=2|  ms | 1084 ms |
| no filters, no sort, limit=32|  ms | 1051 ms |
| no filters, no sort, limit=512|  ms | 1053 ms |
| no filters, no sort, limit=8192|  ms | 1052 ms |
| no filters, no sort, limit=131072|  ms |  ms |
| with age and city filters, no sort, limit=2|  ms | 1205 ms |
| with age and city filters, no sort, limit=32|  ms | 1223 ms |
| with age and city filters, no sort, limit=512|  ms | 1212 ms |
| with age and city filters, no sort, limit=8192|  ms | 1208 ms |
| with age and city filters, no sort, limit=131072|  ms | 1209 ms |
| with age and city filters, no sort, limit=2|  ms | 1215 ms |
| with age and city filters, no sort, limit=32|  ms | 1207 ms |
| with age and city filters, no sort, limit=512|  ms | 1196 ms |
| with age and city filters, no sort, limit=8192|  ms | 1218 ms |
| with age and city filters, no sort, limit=131072|  ms | 1237 ms |
| with age and city filters, name sort, limit=2|  ms | 2903 ms |
| with age and city filters, name sort, limit=32|  ms | 2948 ms |
| with age and city filters, name sort, limit=512|  ms | 2930 ms |
| with age and city filters, name sort, limit=8192|  ms | 2913 ms |
| with age and city filters, name sort, limit=131072|  ms | 3003 ms |
| with age and city filters, relevance sort, limit=2|  ms | - |
| with age and city filters, relevance sort, limit=32|  ms | - |
| with age and city filters, relevance sort, limit=512|  ms | - |
| with age and city filters, relevance sort, limit=8192|  ms | - |
| with age and city filters, relevance sort, limit=131072|  ms | - |
| high selective name, gender filter, no sort, limit=2|  ms | 1045 ms |
| high selective name, gender filter, no sort, limit=32|  ms | 1027 ms |
| high selective name, gender filter, no sort, limit=512|  ms | 1026 ms |
| high selective name, gender filter, no sort, limit=8192|  ms | 1031 ms |
| high selective name, gender filter, no sort, limit=131072|  ms | 1045 ms |
| high selective with age, city and gender filters, no sort, limit=2 |  ms | 1050 ms |
| high selective with age, city and gender filters, no sort, limit=32 |  ms | 1089 ms |
| high selective with age, city and gender filters, no sort, limit=512 |  ms | 1043 ms |
| high selective with age, city and gender filters, no sort, limit=8192 |  ms | 1036 ms |
| high selective with age, city and gender filters, no sort, limit=131072 |  ms | 1054 ms |
| high selective with age and city filters, name sort, limit=2 |  ms | 1146 ms |
| high selective with age and city filters, name sort, limit=32 |  ms | 1137 ms |
| high selective with age and city filters, name sort, limit=512 |  ms | 1139 ms |
| high selective with age and city filters, name sort, limit=8192|  ms | 1126 ms |
| high selective with age and city filters, name sort, limit=131072|  ms | 1162 ms |
| high selective with age and city filters, relevance sort, limit=2|  ms | 67575 ms |
| high selective with age and city filters, relevance sort, limit=32|  ms | 67908 ms |
| high selective with age and city filters, relevance sort, limit=512|  ms | 68043 ms |
| high selective with age and city filters, relevance sort, limit=8192|  ms | 68241 ms |
| high selective with age and city filters, relevance sort, limit=131072|  ms | 57296 ms |
