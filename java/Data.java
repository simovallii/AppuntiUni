
public class Data {
		private int g;    //TODO
		private int m;
		private int a;
		
		public Data(){
			
			this.g = 01;
			this.m = 01;
			this.a = 1970;       // per delegare i costruttori uso this.(01,01,1970) come PRIMA linea di codice
		}
		
		 
		 public String toString() {
			 
			return this.g + "/" + this.m + "/" + this.a; 
		 }
		 
		 public boolean equals(Object obj) {
			 
			 //TODO
			 return true;
		 }
		 
		 
		;
	public static void main(String[] args) {
		
		Data d = new Data();
		
		System.out.println(d);	// ritorna direttamente toString
		
		
		

	}

}
