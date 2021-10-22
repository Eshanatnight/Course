float fastInverseSQRT(float number)
{
    float x2 = number * 0.5f;
    float y = number;
    long i = * (reinterpret_cast<long *> (&y)); 
    const float threehalves = 1.5f;
    
    i = 0x5f3759df - (i >> 1);
    
    y = *(reinterpret_cast<float*> (&i));

    y *= (threehalves - (x2 * y * y));
    y *= (threehalves - (x2 * y * y));
    y *= (threehalves - (x2 * y * y));
   
    return y;
}