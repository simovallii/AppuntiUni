
	import java.util.Scanner;

import javax.print.attribute.standard.MediaSize.Other;

	public class Razionale {
		private int n;
		private int d;
		
		public Razionale() {
			this(0, 1);
		}
		
		public Razionale(int n, int d) {
			if (d == 0)
				throw new RuntimeException("Denominatore uguale a zero");
			this.n = n;
			this.d = d;
		}
		
		public Razionale sum(Razionale other) {
			return new Razionale(n * other.d + d * other.n, d * other.d);
		}
		
		
		
		public void read(Scanner sc) {
			int num, den;
			String line = sc.nextLine();
			
			int sep = line.indexOf("/");
			if (sep == -1) 
				throw new RuntimeException("Errore in lettura");
			
			num = Integer.parseInt(line.substring(0, sep));
			den = Integer.parseInt(line.substring(sep + 1));
			
			if (den == 0)
				throw new RuntimeException("Denominatore uguale a zero");
			
			this.n = num;
			this.d = den;
		}
		
		public int getN() {
			return n;
		}

		public int getD() {
			return d;
		}
		
		@Override
		public String toString() {
			
			return n + "/" + d;
		}
		
		@Override
		public boolean equals (Object obj) {
			
			if (this == obj)
				return true;
			else if(obj == null)
				return false;
			else if(getClass() != obj.getClass())
				return false;
			
		    Razionale other = (Razionale) obj;
			return this.d == other.d && this.n == other.n;
		}
	
		/*
		public boolean equals (Object obj) {
	
			if (this == obj)
				return true;
			else if(obj == null)
				return false;
			else if(!(obj instanceof Razionale))  // controllo le classi di appartenenza, razionale o sue sottoclassi
				return false;
			
		    Razionale other = (Razionale) obj;
			return this.d == other.d && this.n == other.n;    
		}
		*/
		
		public Razionale clone() {
			return new Razionale(this.n, this.d);
		}
	}

