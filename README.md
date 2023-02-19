## Benchmarks

| test | fast | dummy |
|-|-|-|
|getUser| 15201900 ns | 32603500 ns |
|addFriend| 1938300 ns | 16230500 ns |

| findUsers | fast | dummy |
|-|-|-|
| no filters, no sort, limit=2| 2147 ms | 3475 ms |
| no filters, no sort, limit=32| 2147 ms | 3388 ms |
| no filters, no sort, limit=512| 2164 ms | 3435 ms |
| no filters, no sort, limit=8192| 2135 ms | 3332 ms |
| no filters, no sort, limit=131072| 2127 ms | 3389 ms |
| with age and city filters, no sort, limit=2| 2393 ms | 3485 ms |
| with age and city filters, no sort, limit=32| 2474 ms | 3514 ms |
| with age and city filters, no sort, limit=512| 2382 ms | 3480 ms |
| with age and city filters, no sort, limit=8192| 2424 ms | 3491 ms |
| with age and city filters, no sort, limit=131072| 2362 ms | 3512 ms |
| with age and city filters, no sort, limit=2| 2411 ms | 3460 ms |
| with age and city filters, no sort, limit=32| 2425 ms | 3490 ms |
| with age and city filters, no sort, limit=512| 2378 ms | 3509 ms |
| with age and city filters, no sort, limit=8192| 2397 ms | 3590 ms |
| with age and city filters, no sort, limit=131072| 2417 ms | 3519 ms |
| with age and city filters, name sort, limit=2| 2434 ms | 5137 ms |
| with age and city filters, name sort, limit=32| 2434 ms | 5243 ms |
| with age and city filters, name sort, limit=512| 2375 ms | 5153 ms |
| with age and city filters, name sort, limit=8192| 2393 ms | 5177 ms |
| with age and city filters, name sort, limit=131072| 2407 ms | 5377 ms |
| with age and city filters, relevance sort, limit=2| 2413 ms | - |
| with age and city filters, relevance sort, limit=32| 2478 ms | - |
| with age and city filters, relevance sort, limit=512| 2474 ms | - |
| with age and city filters, relevance sort, limit=8192| 2445 ms | - |
| with age and city filters, relevance sort, limit=131072| 2378 ms | - |
| high selective name, gender filter, no sort, limit=2| 2183 ms | 3305 ms |
| high selective name, gender filter, no sort, limit=32| 2159 ms | 3508 ms |
| high selective name, gender filter, no sort, limit=512| 2167 ms | 3332 ms |
| high selective name, gender filter, no sort, limit=8192| 2154 ms | 3311 ms |
| high selective name, gender filter, no sort, limit=131072| 2156 ms | 3398 ms |
| high selective with age, city and gender filters, no sort, limit=2 | 2203 ms | 3377 ms |
| high selective with age, city and gender filters, no sort, limit=32 | 2208 ms | 3398 ms |
| high selective with age, city and gender filters, no sort, limit=512 | 2236 ms | 3345 ms |
| high selective with age, city and gender filters, no sort, limit=8192 | 2269 ms | 3382 ms |
| high selective with age, city and gender filters, no sort, limit=131072 | 2233 ms | 3362 ms |
| high selective with age and city filters, name sort, limit=2 | 2200 ms | 3417 ms |
| high selective with age and city filters, name sort, limit=32 | 2206 ms | 3397 ms |
| high selective with age and city filters, name sort, limit=512 | 2215 ms | 3428 ms |
| high selective with age and city filters, name sort, limit=8192| 2155 ms | 3404 ms |
| high selective with age and city filters, name sort, limit=131072| 2212 ms | 3422 ms |
| high selective with age and city filters, relevance sort, limit=2| 2191 ms | - |
| high selective with age and city filters, relevance sort, limit=32| 2203 ms | - |
| high selective with age and city filters, relevance sort, limit=512| 2181 ms | - |
| high selective with age and city filters, relevance sort, limit=8192| 2161 ms | - |
| high selective with age and city filters, relevance sort, limit=131072| 2211 ms | - |