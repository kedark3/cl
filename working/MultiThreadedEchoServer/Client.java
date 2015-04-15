import java.io.*;
import java.net.*;

public class Client {
	public static void main(String[] args) {
		Socket cs=null;
           	PrintStream ps=null;
           	BufferedReader br=null;
		BufferedReader br1=null;
		String in,out;
		String host="localhost";
		try {
		cs = new Socket(host,6789);
           	ps = new PrintStream(cs.getOutputStream());
           	br = new BufferedReader(new InputStreamReader(cs.getInputStream()));
		br1 = new BufferedReader(new InputStreamReader(System.in));
		}
		catch(Exception e)
		{
		}

	try {
	    while ( true ) {
		System.out.print( "Enter Text (exit to stop connection, quit to stop server): " );
		in = br1.readLine();
		ps.println( in + "\n" );
		if(in.equals("exit"))break;
		out = br.readUTF();
		System.out.println("Server returns as: " + out);
	    }

	    br.close();
	    br1.close();
	    cs.close();   
	} catch (UnknownHostException e) {
	    System.err.println("Trying to connect to unknown host: " + e);
	} catch (IOException e) {
	    System.err.println("IOException:  " + e);
	}
    }           
}
