package it.unipr.calcio;

public class Partita {
	
	private final Squadra squadraX;
	private final Squadra squadraY;
	private final String data;
	
	public Partita(Squadra squadraX, Squadra squadraY, String data) {
		this.squadraX = squadraX;
		this.squadraY = squadraY;
		this.data = data;
	}
	
	public String getData() {
		return data;
	}
	public boolean equals(Object obj) {
		if(this == obj)
			return true;
		if(obj == null)
			return false;
		if(this.getClass() != obj.getClass())
			return false;
		
		Partita other = (Partita) obj;
		return this.squadraX.equals(other.squadraX) && this.squadraY.equals(other.squadraY) && this.data.equals(other.data);
	}
	
}
