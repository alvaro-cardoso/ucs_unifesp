package agenda;

import java.util.ArrayList;
import java.util.List;

public class Contato {
  
  private List<String> emails = new ArrayList<String>();
  private List<String> telefones = new ArrayList<String>();
  
  public List<String> getEmails() {
    return emails;
  }

  public void setEmails(List<String> emails) {
    this.emails = emails;
  }

  public List<String> getTelefones() {
    return telefones;
  }

  public void setTelefones(List<String> telefones) {
    this.telefones = telefones;
  }

  public Contato(List<String> emails, List<String> telefones) {
    this.emails = emails;
    this.telefones = telefones;
  }

  public void adicionaEmail(String email) {
    emails.add(email);
  }

  public void adicionaTelefone(String telefone) {
    telefones.add(telefone);
  }
  
  public void removeEmail(String email) {
    emails.remove(emails.indexOf(email));
  }

  public void removeTelefone(String telefone) {
    telefones.remove(telefones.indexOf(telefone));
  }
}
