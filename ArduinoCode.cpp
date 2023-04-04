const int rua_a_desc_vermelho = 5;
const int rua_a_desc_amarelo = 4;
const int rua_a_desc_verde = 3;
const int rua_a_subin_vermelho = 8;
const int rua_a_subin_amarelo = 7;
const int rua_a_subin_verde = 6;
const int rua_b_vermelho = 11;
const int rua_b_amarelo = 10;
const int rua_b_verde = 9;
const int pedestre_vermelho = 12;
const int pedestre_verde = 13;
const int botao_prioridade = 2;
const int tempo_delayVerde = 4500;
const int tempo_delayAmarelo = 2500;
const int tempo_delayVermelho = 4500;
const int tempo_delayPassagemPedestre = 2500;
bool prioridade_pedestres = false;

void setup()
{
    pinMode(rua_a_desc_vermelho, OUTPUT);
    pinMode(rua_a_desc_amarelo, OUTPUT);
    pinMode(rua_a_desc_verde, OUTPUT);
    pinMode(rua_a_subin_vermelho, OUTPUT);
    pinMode(rua_a_subin_amarelo, OUTPUT);
    pinMode(rua_a_subin_verde, OUTPUT);
    pinMode(rua_b_vermelho, OUTPUT);
    pinMode(rua_b_amarelo, OUTPUT);
    pinMode(rua_b_verde, OUTPUT);
    pinMode(pedestre_vermelho, OUTPUT);
    pinMode(pedestre_verde, OUTPUT);
    pinMode(botao_prioridade, INPUT_PULLUP);
    Serial.begin(9600);
}
// Função responsável por controlar o semáforo da rua A
void rotinaRuaA()
{
    Serial.println("Inicio da rotina A");

    // Abre a rua A e fecha a rua B
    digitalWrite(rua_a_desc_vermelho, LOW);
    digitalWrite(rua_a_subin_vermelho, LOW);
    digitalWrite(rua_a_desc_verde, HIGH);
    digitalWrite(rua_a_subin_verde, HIGH);
    digitalWrite(pedestre_vermelho, HIGH);
    digitalWrite(rua_b_vermelho, HIGH);

    // Aguarda o tempo do verde e realiza a verificação do botão de prioridade 
    delayComVerificacao(tempo_delayVerde);

    // Luzes amarelas na rua A
    digitalWrite(rua_a_desc_verde, LOW);
    digitalWrite(rua_a_subin_verde, LOW);
    digitalWrite(rua_a_desc_amarelo, HIGH);
    digitalWrite(rua_a_subin_amarelo, HIGH);

    // Aguarda o tempo do amarelo e realiza a verificação do botão de prioridade
    delayComVerificacao(tempo_delayAmarelo);

    // Fecha a rua A e abre a rua B
    digitalWrite(rua_a_desc_amarelo, LOW);
    digitalWrite(rua_a_subin_amarelo, LOW);
    digitalWrite(rua_a_desc_vermelho, HIGH);
    digitalWrite(rua_a_subin_vermelho, HIGH);
    digitalWrite(rua_b_vermelho, LOW);
    
    // Raliza a verificação do botão de prioridade
    verificaBotaoPressionado();

    Serial.println("Final da rotina A");
}

// Função responsável por controlar o semáforo da rua B
void rotinaRuaB()
{
    // Imprime mensagem informando o início da rotina
    Serial.println("Inicio da rotina B");

    // Acende luz verde da rua B
    digitalWrite(rua_b_vermelho, LOW);
    digitalWrite(rua_b_verde, HIGH);

    // Aguarda o tempo de verde configurado
    delay(tempo_delayVerde);

    // Troca luz verde por amarela
    digitalWrite(rua_b_verde, LOW);
    digitalWrite(rua_b_amarelo, HIGH);

    // Aguarda o tempo de amarelo configurado
    delay(tempo_delayAmarelo);

    // Troca luz amarela por vermelha
    digitalWrite(rua_b_amarelo, LOW);
    digitalWrite(rua_b_vermelho, HIGH);

    // Imprime mensagem informando o fim da rotina
    Serial.println("Final da rotina B");
}

// Função responsável por controlar o semáforo dos pedestres
void rotinaPedestre()
{
    Serial.println("Inicio da Rotina Pedestre");

    // Seta a rua B como vermelha
    digitalWrite(rua_b_verde, LOW);
    digitalWrite(rua_b_vermelho, HIGH);

    // Abre o semáforo para o pedestre
    digitalWrite(pedestre_vermelho, LOW);
    digitalWrite(pedestre_verde, HIGH);

    // Aguarda o tempo de travessia
    delay(tempo_delayPassagemPedestre);

    // Fecha o semáforo para o pedestre
    digitalWrite(pedestre_verde, LOW);

    // Sinaliza que o semáforo para o pedestre vai fechar
    for (int i = 0; i < 4; i++)
    {
        digitalWrite(pedestre_vermelho, HIGH);
        delay(600);
        digitalWrite(pedestre_vermelho, LOW);
        delay(600);
    }

    // Reseta a prioridade dos pedestres
    prioridade_pedestres = false;

    Serial.println("Final da rotina Pedestre");
}

void verificaBotaoPressionado()
{
    if (digitalRead(botao_prioridade) == LOW)
    {
        prioridade_pedestres = true;
    }
}

void delayComVerificacao(int TempoMilsg)
{
    int numLoops = TempoMilsg / 500;
    for (int i = 0; i < numLoops; i++)
    {
        verificaBotaoPressionado();
        delay(500);
    }
}

void loop()
{

    rotinaRuaA();
    if (prioridade_pedestres == true)
    {
        Serial.println("Rotina Pedestre Preferencial");
        rotinaPedestre();
    }
    rotinaRuaB();
    rotinaPedestre();
}
