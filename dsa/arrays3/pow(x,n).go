package main

func rec(x float64, n int) float64{
    if n == 1 {return x;}
    if n % 2 == 0 {
        small := rec(x, n/2)
        return small * small; 
    }else {
        small := rec(x, n/2)
        return small * small * x; 
    }
}

func myPow(x float64, n int) float64 {
    neg := n < 0
    if neg {
        n = n * -1;
    }
    if n == 0 { return 1.0}
    if x == 0 { return 0.0}
    if neg {
        return 1.0/rec(x,n)
    }
    return rec(x, n)
    // TLE
    // for ; n != 0; n-- {
    //     if neg {
    //         answer /= x;
    //     } else {
    //         answer *= x;
    //     }
    // }
    // return answer;
}