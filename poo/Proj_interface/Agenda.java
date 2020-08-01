package agenda;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Agenda {

  private Map<String, Contato> agenda = new HashMap<String, Contato>();
  
  public Map<String, Contato> getAgenda() {
    return agenda;
  }

  public void adicionaContato(String nome, List<String> emails, List<String> tels) {
    Contato novo = new Contato(emails, tels);
    agenda.put(nome, novo);
  }

  public void adicionaEmail(String nome, String email) {
    Contato c = agenda.get(nome);
    if (c != null)
      c.adicionaEmail(email);
  }

  public void adicionaTelefone(String nome, String telefone) {
    Contato c = agenda.get(nome);
    if (c != null)
      c.adicionaTelefone(telefone);
  }

  public void removeEmail(String nome, String email) {
    Contato c = agenda.get(nome);
    if (c != null)
      c.removeEmail(email);
  }

  public void removeTelefone(String nome, String telefone) {
    Contato c = agenda.get(nome);
    if (c != null)
      c.removeEmail(telefone);
  }

  public Contato buscaContato(String nome) {
    return agenda.get(nome);
  }


}
