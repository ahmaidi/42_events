 #include <stdio.h>

int main(int ac, char**ar)
{
    int i = 0;
    int res = 0;
    int flag = 1;
    int countA = 0;
    if (ac == 2)
    {
        while (ar[1][i])
        {
            if (ar[1][i] >= '2' && ar[1][i] <= '9')
                res += ar[1][i] - '0';
            else if (ar[1][i] =='T' || ar[1][i] =='J' || ar[1][i] =='D' || ar[1][i] =='K' || ar[1][i] =='A')
            {
                if (ar[1][i] =='A')
                {
                    countA++;
                    res +=11;
                }
                else
                    res+=10;
            }
            else
            {
                flag = 0;
                break ;
            }
            i++;
        }
        while (countA > 0 && res > 21)
        {
            res-=10;
            countA--;
        }
    }
    if (flag)
    {
        if (res != 21)
            printf("%d\n",res);
        else
            printf("Blackjack!\n");
    }
    return (0);
}