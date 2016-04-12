//$
//Bu fonksiyon iki numarayı birbirine ekler
//number1 ilk değerdir
//number2 2. değerdir
//$

public int AddNumbers(int number1, int number2)
{
    int result = number1 + number2;
    if(result > 10)
    {
        return result;
    }
    return 0;
}