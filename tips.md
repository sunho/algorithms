# c++

## 2d array initialization

```c++
#include <cstring>
int n[N][N];
memset(n, <initial-value>, sizeof n);
```

## pair add operator

```c++
template <typename T,typename U>                                                   
std::pair<T,U> operator+(const std::pair<T,U> & l, const std::pair<T,U> & r) {   
    return {l.first+r.first, l.second+r.second};                                    
} 
```

Works in c++11.
