public class Main {
    
    public static double[][] crearMatriz(int rows, int cols){
        
        double arr[][] = new double[rows][cols];
        
        for(int i  = 0 ; i < rows; i++){
            for(int j = 0; j < cols; j++){
                arr[i][j] = Math.random();
            }
        }
    
        return arr;
        
    }
    
    public static double[][] matmul(double[][] A, double[][] B){
        if (B.length != A[0].length){
            
            System.out.println("No se puede hacer esta operacion");
            double[][] na = {{0.0}};
            return na;
        }
          
        int rows_out = A.length;
        int cols_out = B[0].length;
        double out[][] = crearMatriz(rows_out, cols_out);
        
        for (int i = 0; i < rows_out; i++){
            for (int j = 0; j <cols_out; j++){
                for(int k = 0; k < B.length; k++ ){
                    out[i][j] += A[i][k] * B[k][j];
                }
            } 
        }
                
        return out;
    }
    
    
    public static void main(String args[]) {
        double[][] a = crearMatriz(600, 100);
        double[][] b = crearMatriz(100, 600);
        
        double tiempo = 0.0;
        
        for(int i = 0; i< 10; i++){
            long inicio = System.currentTimeMillis();
        
            double[][] x = matmul(a,b);
        
            long fin = System.currentTimeMillis();
            
            tiempo += (fin - inicio);
        }
        
        System.out.println("Tiempo en ms 600x100 * 100x600 ");
        System.out.println(tiempo/10);
        
        double[][] c = crearMatriz(100, 100);
        double[][] d = crearMatriz(100, 100);
        
        tiempo = 0.0;
        
        for(int i = 0; i< 10; i++){
            long inicio = System.currentTimeMillis();
        
            double[][] x = matmul(c,d);
        
            long fin = System.currentTimeMillis();
            
            tiempo += (fin - inicio);
        }
        System.out.println("Tiempo en ms 100x100 * 100x100");
        System.out.println(tiempo/10);

        
    }
}
