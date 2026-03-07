fun main(){
    fun generateLetters() : List<Char>{
        val alpha = arrayOf<Char>('A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z')
        val list = mutableListOf<Char>()

        for(i in 0 until 8){
        list.add(alpha.random())
    }
        return list
    }

    fun isWordAllowed(word : String, letters : List<Char>) : Boolean {
        var mappa = mutableMapOf<Char, Int>()

        for (c in letters){

            if (c in mappa.keys) {
                mappa.put(c, mappa.getValue(c) + 1)
            }
            else{
                mappa.put(c, 1)
            }
        }
        for (c in word){
            if (!mappa.keys.contains(c) || mappa[c] == 0){
                return false
            }
            else {
                mappa[c] = mappa[c]!! - 1
            }
        }
        return true;
    }

    fun computeScore(word : String, scores : Map<Char, Int>) : Int{
        var punteggio = 0
        for(letter in word){
            punteggio += scores.getOrDefault(letter, 0)
        }
        return punteggio
    }

    val scores = mutableMapOf<Char, Int>()
    for(c in "ABCDEFGHIJKLMNOPQRSTUVWXYZ"){
        when(c){
            in "AEIOULNRST" -> scores.put(c, 1)
            in "DG" -> scores.put(c, 2)
            in "BCMP" -> scores.put(c, 3)
            in "FHVWY" -> scores.put(c, 4)
            in "K" -> scores.put(c, 5)
            in "JX" -> scores.put(c, 8)
            in "QZ" -> scores.put(c, 10)
        }
    }

    val lettereGenerate = generateLetters()
    println("le lettere sono $lettereGenerate")
    println("inserisci la parola")
    val parolaInserita : String = readLine() ?: "empty"

    if(!isWordAllowed(parolaInserita,lettereGenerate))
        println("parola non valida!")
    else
        println("Hai totalizzato ${computeScore(parolaInserita, scores)} punti")
}