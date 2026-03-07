//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
fun main() {

    fun isValidDna(seq: String): Boolean {
        for (c in seq) {
            if (c !in "TCGA") {
                return false
            }
        }
        return true
    }

    fun hammingDistance(seq1: String, seq2: String): Int {
        if (seq1.length != seq2.length) {
            return 0
        }
        var count = 0
        for(i in 0 until seq1.length){
            when(seq1.get(i) == seq2.get(i)){
                true -> 0
                false -> count++
            }
        }
        return count
    }

    val s1 : String =  readLine() ?: "empty"
    val s2 : String =  readLine() ?: "empty"

    if(isValidDna(s1) && isValidDna(s2)) {
        println(hammingDistance(s1, s2))
    }
    else{
        println("distance not possible")
    }
}