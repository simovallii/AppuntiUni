package it.unipr.festival;

public class Esibizione {
	
	private final Partecipante partecipante;
	private final String dataOra;
	
	public Esibizione(Partecipante partecipante, String dataOra) {
		this.partecipante = partecipante;
		this.dataOra = dataOra;
	}
	
	public Partecipante getPartecipante() {
		return partecipante;
	}
	
	public String getDataOra() {
		return dataOra;
	}
	
	// metodo equals non richiesto
}
