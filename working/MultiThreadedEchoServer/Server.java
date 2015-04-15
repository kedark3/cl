import java.io.*;
import java.net.*;

public class Server {
public static void main(String args[]) 
{
	Server s = new Server( 6789 );
	s.startServer();
}
	ServerSocket ss = null;
    	Socket cs = null;
   	int numConnections = 0;
    	int port;
		public Server( int port )
		{
			this.port = port;
		}

    		public void stopServer()
		{
			System.out.println( "Server cleaning up." );
			System.exit(0);
		}

   		public void startServer()
		{
        		try
			{
				    ss = new ServerSocket(port);
        		}
      			catch (IOException e)
			{
	    			System.out.println(e);
        		}   
			System.out.println( "Server is started and is waiting for connections." );
			System.out.println( "With multi-threading, multiple connections are allowed." );
			System.out.println( "Any client can send 'exit' to stop the server." );
	
			while ( true ) 
			{
		    		try
				{
					cs = ss.accept();
					numConnections ++;
					connection c = new connection(cs, numConnections, this);
					new Thread(c).start();
		    		}   
		    		catch (IOException e)
				{
					System.out.println(e);
		   		}
			}
	   	}



class connection implements Runnable {
    BufferedReader br=null;
    PrintStream ps=null;
    Socket cs=null;
    int id;
    Server s;

    public connection(Socket cs, int id, Server s) {
	this.cs = cs;
	this.id = id;
	this.s = s;
	System.out.println( "Connection " + id + " established with: " + cs );
	try {
	    br = new BufferedReader(new InputStreamReader(cs.getInputStream()));
	    ps = new PrintStream(cs.getOutputStream());
	} catch (IOException e) {
	    System.out.println(e);
	}
    }

public void run()
{
        String line;
	boolean serverStop = false;
	try 
	{
	    	
		while (true) {
            	br = new BufferedReader(new InputStreamReader(cs.getInputStream()));
		ps = new PrintStream(cs.getOutputStream());
                line = br.readLine();
                System.out.println( "Received " + line + " from Connection " + id + "." );
                if(line.equals("quit")) break;
                ps.print(line);
         }
	}
	catch (IOException e) {}
	    System.out.println( "Connection " + id + " closed." );
            //br.close();
            //ps.close();
            //cs.close();
	    serverStop=true;

	    if ( serverStop ) s.stopServer();
	}
}
}
