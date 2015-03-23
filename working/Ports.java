import java.io.*;
import java.net.*;

public class Ports{
	public static void main(String[] args)
	{
		int start=0;
		int end=65535;
		
		for(int i= start ; i<= end; i++)
		{
			try {
	            	Socket clientSocket = new Socket("localhost", i);
	            	System.out.println("port " + i +" is in use");
	            }
	       catch(Exception e)
	       {
	       	}
	     }
	}
};


/*
Output:

exam@CCOMPL08-05:~/Desktop$ javac Ports.java
exam@CCOMPL08-05:~/Desktop$ java Ports
port22 is in use
port80 is in use
port111 is in use
port631 is in use
port3306 is in use
port39063 is in use
port56425 is in use
port59866 is in use
exam@CCOMPL08-05:~/Desktop$ 
*/
