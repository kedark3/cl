import java.io.*;
import java.net.*;

public class Server2 {
    public static void main(String args[]) {
	int port = 6789;
	Server2 server = new Server2( port );
	server.startServer();
    }

    // declare a server socket and a client socket for the server;
    // declare the number of connections

    ServerSocket echoServer = null;
    Socket clientSocket = null;
    int numConnections = 0;
    int port;
	
    public Server2( int port ) {
	this.port = port;
    }

    public void stopServer() {
	System.out.println( "Server cleaning up." );
	System.exit(0);
    }

    public void startServer() {
	// Try to open a server socket on the given port
	// Note that we can't choose a port less than 1024 if we are not
	// privileged users (root)
	
        try {
	    echoServer = new ServerSocket(port);
        }
        catch (IOException e) {
	    System.out.println(e);
        }   
	
	System.out.println( "Server is started and is waiting for connections." );
	System.out.println( "With multi-threading, multiple connections are allowed." );
	System.out.println( "Any client can send 'bye' to stop the server." );

	// Whenever a connection is received, start a new thread to process the connection
	// and wait for the next connection.
	
	while ( true ) {
	    try {
		clientSocket = echoServer.accept();
		numConnections ++;
		Server2Connection oneconnection = new Server2Connection(clientSocket, numConnections, this);
		new Thread(oneconnection).start();
	    }   
	    catch (IOException e) {
		System.out.println(e);
	    }
	}
    }
}

class Server2Connection implements Runnable {
    BufferedReader is;
    DataOutputStream os;
    Socket clientSocket;
    int id;
    Server2 server;

    public Server2Connection(Socket clientSocket, int id, Server2 server) {
	this.clientSocket = clientSocket;
	this.id = id;
	this.server = server;
	System.out.println( "Connection " + id + " established with: " + clientSocket );
	try {
	    is = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
	    os = new DataOutputStream(clientSocket.getOutputStream());
	} catch (IOException e) {
	    System.out.println(e);
	}
    }

    public void run() {
        String line;
	try {
	    boolean serverStop = false;

            while (true) {
            line = is.readLine();
            if ( line.equals("bye") ) {
		    serverStop = true;
		    break;
		}
                
		System.out.println( "Client Says: " + line + " from Connection " + id + "." );
		
        System.out.print( "Enter a message : " );
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String keyboardInput = br.readLine();
		os.writeBytes( keyboardInput + "\n" );      
		
		if ( keyboardInput.equals("bye") ) {
		    serverStop = true;
		    break;
		}
	}

	    System.out.println( "Connection " + id + " closed." );
            is.close();
            os.close();
            clientSocket.close();

	    if ( serverStop ) server.stopServer();
	} catch (IOException e) {
	    System.out.println("Exception" + e);
	}
    }
}

/*
Output:
exam@CCOMPL08-05:~/Downloads$ java Server2
Server is started and is waiting for connections.
With multi-threading, multiple connections are allowed.
Any client can send quit to stop the server.
Connection 1 established with: Socket[addr=/172.20.55.24,port=51984,localport=6789]
Client Says: hii from Connection 1.
Enter a message : hello
Client Says: how are you? from Connection 1.
Enter a message : I'm fine, How are you? 
Client Says: just fine :) from Connection 1.
Enter a message : Btw GoodMornin'
Client Says: gm from Connection 1.
Enter a message : So hows the weather there?
Client Says: cold,cause i didnt wear sweater like u from Connection 1.
Enter a message : ohk, let's talk sometime later!
Connection 1 closed.
Server cleaning up.
exam@CCOMPL08-05:~/Downloads$ 

*/
