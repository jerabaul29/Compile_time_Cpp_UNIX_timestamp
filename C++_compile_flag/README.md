To compile on Ubuntu:

```[language=bash]
g++ -DUNIX_TIMESTAMP=$(echo $(date +%s)) compile_time.cpp
```

This will give the following example output:

```[language=bash]
jrlab@jrlab-T150s:~/Desktop/Git/PlayingWithCpp/compile_time$ g++ -DUNIX_TIMESTAMP=$(echo $(date +%s)) compile_time.cpp 
jrlab@jrlab-T150s:~/Desktop/Git/PlayingWithCpp/compile_time$ date +%s
1522939894
jrlab@jrlab-T150s:~/Desktop/Git/PlayingWithCpp/compile_time$ ./a.out 
UNIX timestamp 1522939892
```
