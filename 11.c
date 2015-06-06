int maxArea(int height[], int n) {
    int i=0;
    int j = n-1;
    int gaom = 0;
    int gaon = 0;
    int area = 0;
    int max = 0;
    
    while(i < j)
    {
        gaom = height[i];
        gaon = height[j];
        
        
        if(gaom < gaon)
        {
            area = height[i]*(j-i);
            i++;
            while((height[i] <= gaom) && (i < j))
            {
                i++;
            }
        }
        else
        {
            area = height[j]*(j-i);
            j--;
            while((height[j] <= gaon) && (i < j))
            {
                j--;
            }
            
        }
        
        if(area > max)
        {
            max = area;
        }
        
        
        
    }
    return max;
    
    
}