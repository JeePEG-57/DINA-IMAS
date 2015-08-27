import org.zeromq.ZMQ;
import java.util.StringTokenizer;

public class SimSRFLAG {

    public static ZMQ.Context context;
    public static ZMQ.Socket socket;
    public static int sizetab=150;

    public static void init() {
        // Prepare our context and socket
        context = ZMQ.context(1);
        socket = context.socket(ZMQ.REQ);
        socket.connect("tcp://localhost:5555");
        System.err.println("connected to kepler:");
    }

    public static void send(int flag) {        
        System.err.print("SimSRFlag send begin, value="+flag+"\n");
        String update = String.format("%d\u0000",flag);
        socket.send(update.getBytes(),0); 
        System.err.printf("SimSRFlag send ok\n");
       }

    public static void senddata(Double[] anArray) {        
        //double[] anArray;
        String data;

        System.err.print("SimSRFlag send data begin\n");
        // allocates memory
        //anArray = new double[sizetab];
        /*
        for (int i=0;i< sizetab;i++) {
            anArray[i]=i;
        } 
        */ 
        data=String.valueOf(anArray[0]);
        for (int i=1;i< anArray.length;i++) {
            data=data+" "+String.valueOf(anArray[i]);
        }
        data=data+"\u0000";
        socket.send(data.getBytes(),0); 
        System.err.printf("SimSRFlag send data ok:"+data+"\n");
       }

     public static int recv() {
       int flag=0;
       System.err.printf("SimSRFlag recv begin\n");
       String string = new String(socket.recv(0)).trim();
       StringTokenizer sscanf = new StringTokenizer(string, " ");
       String t = sscanf.nextToken();
       flag = Integer.valueOf(t);
       System.err.printf("SimSRFlag recv ok, value="+flag+"\n");
       return flag;
     }

     public static double[] recvdata() {
       double[] anArray;

       System.err.printf("SimSRFlag recv data begin\n");
       // allocates memory
        anArray = new double[sizetab];

       String string = new String(socket.recv(0)).trim();
       StringTokenizer sscanf = new StringTokenizer(string, " ");
       String t;
       System.err.printf("SimSRFlag recv data ok, value=");
       for (int i=0;i< sizetab;i++) {
            t = sscanf.nextToken();
            anArray[i]=Double.valueOf(t);
            System.err.printf(anArray[i]+" ");
        }  
       System.err.printf("\n");
       return anArray;
     }


     public static void close() {
        socket.close();
        context.term();
        System.err.println("close connection to Kepler");
     }
/*
    public static void main(String[] args) {
       int flag=1;
       init();
       send(flag);
       flag=recv();
       senddata();
       recvdata();
       close();
     } 
*/
}


