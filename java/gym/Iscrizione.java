package it.unipr.gym;

public class Iscrizione {
	private final Utente utente;
	private final int meseInizio;
	private final int annoInizio;
	private final int meseFine;
	private final int annoFine;
	
	
	
	public Iscrizione(Utente utente, int meseInizio, int meseFine, int annoInizio, int annoFine) {
		
		if (annoInizio > annoFine)
			throw new IscrizioneNonValidaException("iscrizione non valida");
		if (meseInizio > meseFine)
			throw new IscrizioneNonValidaException("iscrizione non valida");
		if(annoInizio != annoFine && meseInizio < meseFine)
			throw new IscrizioneNonValidaException("iscrizione non valida");
	
	
		this.utente = utente;
		this.meseInizio = meseInizio;
		this.meseFine = meseFine;
		this.annoInizio = annoInizio;
		this.annoFine = annoFine; 

		
	}
	
	public boolean overlapseWith(Iscrizione other) {
		
		
	}
}
