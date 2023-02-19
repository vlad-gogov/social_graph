## Benchmarks

| test | fast | dummy |
|-|-|-|
|getUser| 29746200 ns | 32603500 ns |
|addFriend| 2620600 ns | 16230500 ns |

| findUsers | fast | dummy |
|-|-|-|
| no filters, no sort, limit=2| 2370 ms | 3475 ms |
| no filters, no sort, limit=32| 2440 ms | 3388 ms |
| no filters, no sort, limit=512| 2404 ms | 3435 ms |
| no filters, no sort, limit=8192| 2397 ms | 3332 ms |
| no filters, no sort, limit=131072| 2810 ms | 3389 ms |
| with age and city filters, no sort, limit=2| 2845 ms | 3485 ms |
| with age and city filters, no sort, limit=32| 2492 ms | 3514 ms |
| with age and city filters, no sort, limit=512| 2461 ms | 3480 ms |
| with age and city filters, no sort, limit=8192| 2445 ms | 3491 ms |
| with age and city filters, no sort, limit=131072| 2456 ms | 3512 ms |
| with age and city filters, no sort, limit=2| 2360 ms | 3460 ms |
| with age and city filters, no sort, limit=32| 2476 ms | 3490 ms |
| with age and city filters, no sort, limit=512| 2459 ms | 3509 ms |
| with age and city filters, no sort, limit=8192| 2463 ms | 3590 ms |
| with age and city filters, no sort, limit=131072| 2480 ms | 3519 ms |
| with age and city filters, name sort, limit=2| 4972 ms | 5137 ms |
| with age and city filters, name sort, limit=32| 4971 ms | 5243 ms |
| with age and city filters, name sort, limit=512| 5014 ms | 5153 ms |
| with age and city filters, name sort, limit=8192| 4936 ms | 5177 ms |
| with age and city filters, name sort, limit=131072| 5079 ms | 5377 ms |
| with age and city filters, relevance sort, limit=2| 2610 ms | - |
| with age and city filters, relevance sort, limit=32| 2653 ms | - |
| with age and city filters, relevance sort, limit=512| 2688 ms | - |
| with age and city filters, relevance sort, limit=8192| 2673 ms | - |
| with age and city filters, relevance sort, limit=131072| 2641 ms | - |
| high selective name, gender filter, no sort, limit=2| 2391 ms | 3305 ms |
| high selective name, gender filter, no sort, limit=32| 2432 ms | 3508 ms |
| high selective name, gender filter, no sort, limit=512| 2420 ms | 3332 ms |
| high selective name, gender filter, no sort, limit=8192| 2404 ms | 3311 ms |
| high selective name, gender filter, no sort, limit=131072| 2371 ms | 3398 ms |
| high selective with age, city and gender filters, no sort, limit=2 | 2362 ms | 3377 ms |
| high selective with age, city and gender filters, no sort, limit=32 | 2409 ms | 3398 ms |
| high selective with age, city and gender filters, no sort, limit=512 | 2442 ms | 3345 ms |
| high selective with age, city and gender filters, no sort, limit=8192 | 2410 ms | 3382 ms |
| high selective with age, city and gender filters, no sort, limit=131072 |2429 ms | 3362 ms |
| high selective with age and city filters, name sort, limit=2 |2515 ms | 3417 ms |
| high selective with age and city filters, name sort, limit=32 |2397 ms | 3397 ms |
| high selective with age and city filters, name sort, limit=512 |2495 ms | 3428 ms |
| high selective with age and city filters, name sort, limit=8192| 2471 ms | 3404 ms |
| high selective with age and city filters, name sort, limit=131072| 2476 ms | 3422 ms |
| high selective with age and city filters, relevance sort, limit=2| 2368 ms | - |
| high selective with age and city filters, relevance sort, limit=32| 2411 ms | - |
| high selective with age and city filters, relevance sort, limit=512| 2417 ms | - |
| high selective with age and city filters, relevance sort, limit=8192| 2444 ms | - |
| high selective with age and city filters, relevance sort, limit=131072| 2430 ms | - |
