package it.unipr.lavoro;

public class ImpiegatoBase extends Impiegato{
	
	private static double importoOrario = 15.50;
	
	public ImpiegatoBase(String nome, String cognome, int ore) {
		super(nome, cognome, ore);
	}
	
	public double getStipendioAnnuale() {
		double stipendio = 0;
		
		stipendio = importoOrario * this.getOre();
		return stipendio;
	}
	
	public boolean equals(Object obj) {
		return super.equals(obj);
	}
}
