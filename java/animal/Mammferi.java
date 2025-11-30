package it.unipr.animal;

public class Mammferi extends Animali{
	
		private String specie;
		
		public Mammferi(String nome, int eta, String specie) {
			
			super(nome, eta);
			this.specie = specie;
		}
		
		public Mammferi() {
			this("nessun animale", 0, "nessuna specie");
		}
		
		public String toString() {
			return super.toString() + ", " + specie;
		}
		
		public boolean equals(Object obj) {
			if (this == obj) 
				return true;
			if (obj == null)
				return false;
			if (this.getClass() !=  obj.getClass())
				return false;
			
			Mammferi other = (Mammferi) obj;
			
			return super.equals(obj) && specie.equals(other.specie);
		}
}
