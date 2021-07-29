class Solution{
public:
    
    long count(int x, int Y[], int n, int NoOfY[])
    {
        // If x is 0, then there cannot be any value in Y such
        // that x^Y[i] > Y[i]^x
        if (x == 0)
            return 0;
     
        // If x is 1, then the number of pais is equal to number
        // of zeroes in Y[]
        if (x == 1)
            return NoOfY[0];
     
        // Find number of elements in Y[] with values greater
        // than x upper_bound() gets address of first greater
        // element in Y[0..n-1]
        int* idx = upper_bound(Y, Y + n, x);
        long ans = (Y + n) - idx;
     
        // If we have reached here, then x must be greater than
        // 1, increase number of pairs for y=0 and y=1
        ans += (NoOfY[0] + NoOfY[1]);
     
        // Decrease number of pairs for x=2 and (y=4 or y=3)
        if (x == 2)
            ans -= (NoOfY[3] + NoOfY[4]);
     
        // Increase number of pairs for x=3 and y=2
        if (x == 3)
            ans += NoOfY[2];
     
        return ans;
    }
    
    // X[], Y[]: input arrau
    // M, N: size of arrays X[] and Y[] respectively
    //Function to count number of pairs such that x^y is greater than y^x.
    long long countPairs(int X[], int Y[], int M, int N)
    {
        int NoOfY[5] = { 0 };
        for (int i = 0; i < N; i++)
            if (Y[i] < 5)
                NoOfY[Y[i]]++;
        
        // Sort Y[] so that we can do binary search in it
        sort(Y, Y + N);
        
        long long total_pairs = 0; // Initialize result
        
        // Take every element of X and count pairs with it
        for (int i = 0; i < M; i++)
            total_pairs += count(X[i], Y, N, NoOfY);
        
        return total_pairs;
    }
};
