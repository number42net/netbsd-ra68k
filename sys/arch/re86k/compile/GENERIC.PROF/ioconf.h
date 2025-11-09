
/* pseudo-devices */
void cpuctlattach(int);
void rndattach(int);
void putterattach(int);
void accf_dataattach(int);
void accf_httpattach(int);
void slattach(int);
void pppattach(int);
void loopattach(int);
void bpfilterattach(int);
void gifattach(int);
void stfattach(int);
void ptyattach(int);
void vndattach(int);
void fssattach(int);
void clockctlattach(int);
void ksymsattach(int);
void swwdogattach(int);
void drvctlattach(int);
void cryptoattach(int);
void swcryptoattach(int);

/* driver structs */
extern struct cfdriver swwdog_cd;
extern struct cfdriver vnd_cd;
extern struct cfdriver fss_cd;
extern struct cfdriver mainbus_cd;
extern struct cfdriver duart_cd;
