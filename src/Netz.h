#pragma once

struct Script;


#pragma pack(push, 1)

/* 400 */
struct netz_stru0
{
    char player_name[8];
    int field_8;
    char date[12];
    char time[9];
};

/* 401 */
struct netz_stru1
{
    char field_0;
    char field_1;
    char field_2;
    char field_3;
    netz_stru0 stru0;
    char field_25[247];
    int field_11C;
};


/* 440 */
struct netz_provider
{
    char *(*get_error_name)();
    const char *string_4;
    const char *string_8;
    const char *string_C;
    int is_directplay_initialized;
    int field_14;
    int field_18;
    void *pfn_1C;
    void *pfn_20;
    void *field_24;
    void *field_28;
    void *field_2C;
    void *field_30;
    void *field_34;
    void *field_38;
    void *field_3C;
    void *field_40;
    void *field_44;
    void *field_48;
    void *field_4C;
    void *field_50;
    void *field_54;
    void *field_58;
    void *field_5C;
    void *field_60;
    void *field_64;
};

/* 441 */
struct netz_stru_3
{
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    const char *str_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
};

/* 442 */
struct netz_stru_4
{
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
};


/* 448 */
struct netz_stru_5
{
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
};

/* 450 */
struct netz_stru6_per_player
{
    char str_0[4];
    int ptr_4;
    char field_8;
    char field_9;
    char field_A;
    char player_name[9];
    int field_14;
    int field_18;
};

/* 463 */
struct netz_modem
{
    netz_modem *next;
    netz_modem *prev;
    char name[12];
    char phone[12];
    int baud;
};

#pragma pack(pop)

int netz_42E170(int a1, char *a2);
bool netz_free_provider_async();
void *netz_42E400(void *a1);
char *netz_42E410(int a1);
bool netz_42E430(int a1);
bool netz_42E7B0();
void netz_42E7F0();
int netz_42E820(netz_stru_3 *a1);
void netz_42F620();
int __stdcall netz_nullsub_5(int a1, int a2);
int netz_init(int netz_provider_id, void(*a2)(), int(*a3)(int)); // idb
int netz_42F8C0(int a1);
int netz_42F8E0(int a1);
int netz_42F930_switch_provider(int netz_provider_id);
void netz_free_provider();
void netz_deinit();
int netz_42F9C0(int a1, int a2);
int netz_42F9E0(int a1);
int netz_42FA00(int a1, int a2, void *a3, int a4, int a5); // idb
int netz_42FAC0(const char *provider);
bool netz_42FB60_init_provider(int provider_id);
void netz_cleanup();
void netz_42FD30(int a1);
bool netz_42FF10(int a1, char a2, void *a3, unsigned int a4, int a5); // idb
bool netz_42FFB0(int a1, int a2);
bool j_netz_42FFB0(int a1, int a2);
int netz_4300C0(int a1);
int netz_4301E0(int a1);
int netz_430340();
int netz_430610();
int j_netz_430610();
int netz_430640();
int j_netz_430640();
int netz_430670(int a1);
int j_netz_430670(int a1);
int netz_430690();
int j_netz_430690();
BOOL __stdcall DirectPlayEnumerateACallback(LPGUID lpguidSP, LPSTR lpSPName, DWORD dwMajorVersion, DWORD dwMinorVersion, LPVOID lpContext); // idb
int netz_create_direct_play(int a1);
bool netz_430910_dplay();
bool __stdcall netz_4309A0(int a1, int a2, char a3, int a4);
bool __stdcall netz_430A70(int a1, int a2, int a3, char a4, int a5);
int netz_430B10(int a1, int a2);
int netz_430CE0();
int netz_430D10();
int netz_430D70(int a1);
int netz_430DA0(unsigned int a1);
char *netz_get_error_string(int error_code); // idb

void script_449820_netz(Script *); // idb
bool netz_449E00(_DWORD *a1, unsigned int a2, const char *a3);
void netz_449FF0();
void netz_44A160(char a1, char *a2, int a3);
void *netz_44A220(char a1, char *a2, int a3);
void netz_44A2A0(char a1, int a2, int a3);
void *netz_42E450(void *a1, char a2, char a3);
void *netz_42E690(void *a1, char a2);
void *netz_42F650(void *a1);

extern netz_stru6_per_player netz_47A740[8];
extern int(*netz_pfn_47A838)(netz_stru_3 *);

extern netz_stru_4 netz_47A8E4;
extern netz_stru_5 netz_47A940[8];
extern netz_stru1 netz_47AAA0[8];

extern int netz_468B6C_providers_idx; // weak
extern netz_provider netz_468B6C_providers[3];
extern char aDirectxModem[]; // idb
extern char aDirectxSerial[]; // idb
extern char aDirectxIpx[]; // idb
extern char *netz_468CD8_datetime[2];
extern char netz_default_player_name[7];