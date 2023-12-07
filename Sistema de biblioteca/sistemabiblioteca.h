typedef struct lista Lista;

Lista* lst_cria(void);

Lista* lst_insere(Lista* l, char* v,char *livro,int d_ent,int m_ent,int a_ent);

void lst_imprime(Lista* l);

Lista* lst_busca(Lista* l, char* v);

Lista* lst_retira(Lista* l, char* v);

void menu();