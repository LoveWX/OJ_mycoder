import java.util.*;
import java.math.*;
import java.io.*;

public class Main
{
	public static void main(String[]args)
	{
		Scanner cin=new java.util.Scanner(System.in);
		BigInteger a=new BigInteger("0");
		BigInteger b=new BigInteger("0");
		while(cin.hasNext())
		{
            a=cin.nextBigInteger();
            b=cin.nextBigInteger();
            a=a.multiply(b);
            System.out.println(a);
		}
	}
}