import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) {
	
	String hostname = "172.20.55.25";
	int port = 6789;

	
	
        Socket clientSocket = null;  
        DataOutputStream os = null;
        BufferedReader is = null;
	
	
        try {
            clientSocket = new Socket(hostname, port);
            os = new DataOutputStream(clientSocket.getOutputStream());
            is = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        } catch (UnknownHostException e) {
            System.err.println("Don't know about host: " + hostname);
        } catch (IOException e) {
            System.err.println("Couldn't get I/O for the connection to: " + hostname);
        }
	
	// If everything has been initialized then we want to write some data
	// to the socket we have opened a connection to on the given port
	
	if (clientSocket == null || os == null || is == null) {
	    System.err.println( "Something is wrong. One variable is null." );
	    return;
	}

	try {
	    while ( true ) {
		System.out.print( "Enter a message (bye to stop connection): " );
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String keyboardInput = br.readLine();
		os.writeBytes( keyboardInput + "\n" );


		if (keyboardInput.equals("bye")) {
		    break;
		}
		
		String responseLine = is.readLine();
		System.out.println("Server: " + responseLine);
		if (responseLine.equals("bye")) {
		    break;
		}
	    }
	    
	    // clean up:
	    // close the output stream
	    // close the input stream
	    // close the socket
	    
	    os.close();
	    is.close();
	    clientSocket.close();   
	} catch (UnknownHostException e) {
	    System.err.println("Trying to connect to unknown host: " + e);
	} catch (IOException e) {
	    System.err.println("IOException:  " + e);
	}
    }           
}
/*
exam@CCOMPL08-04:~$ cd Desktop
exam@CCOMPL08-04:~/Desktop$ javac Client.java
exam@CCOMPL08-04:~/Desktop$ java Client
Enter a message (bye to stop connection): hii
Server: hello
Enter a message (bye to stop connection): how are you?
Server: I'm fine, How are you? 
Enter a message (bye to stop connection): just fine :)
Server: Btw GoodMornin'
Enter a message (bye to stop connection): gm
Server: So hows the weather there?
Enter a message (bye to stop connection): cold,cause i didnt wear sweater like u
Server: ohk, let's talk sometime later!
Enter a message (bye to stop connection): bye
exam@CCOMPL08-04:~/Desktop$ 

*/
