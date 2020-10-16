import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Day11 {



    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int[][] arr = new int[6][6];

        for (int i = 0; i < 6; i++) {
            String[] arrRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 6; j++) {
                int arrItem = Integer.parseInt(arrRowItems[j]);
                arr[i][j] = arrItem;
            }
        }
        int s,max=0;
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<6;j++)
            {
                s=0;
                if(i<4 && j<4)
                {
                    for(int k=i;k<(i+3);k++)
                    {
                        for(int d=j;d<(j+3);d++)
                        {
                            if((arr[k][d]!=0) && (arr[k][d]>=-9) && (arr[k][d]<=9))
                            {
                                if(k!=i+1)
                                {
                                    s=s+arr[k][d];
                                }
                                else if((k==i+1) && (d==j+1))
                                {
                                    s=s+arr[k][d];
                                }
                            }
                        }
                    }
                    if(s>max || (i==0 && j==0))
                    {
                        max=s;
                    }
                }
            }
        }
        System.out.println(max);
        scanner.close();
    }
}

