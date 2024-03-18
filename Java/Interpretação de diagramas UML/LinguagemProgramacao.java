interface Pratica
{
    String getLaboratorio();
}

public abstract class Disciplina
{
    public int codigo;
    
    public void setCodigo(int codigo)
    public int getCodigo()
    public abstract float calcularMedia()
}

public class LinguagemProgramacao extends Disciplina implements Pratica
{
    private String laboratorio;
    
    public LinguagemProgramacao()
    public void setLaboratorio(String laboratorio)
    public String getLaboratorio()
    public float calcularMedia()
}