#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//Deklarasi data struct

struct history
{
    char come[20];
    char tujuan[20];
    char tujuanBank[20];
    float uang;
};

struct acc_type
{
    char nomorRekening[20];
    int transferBerapa;
    char acc_email[40];
    char acc_pass[20];
    char bank_name[20];
    char bank_branch[20];
    char acc_holder_name[40];
    int acc_number;
    char acc_holder_address[100];
    float available_balance;
    struct history his[50];
};
struct acc_type account[20];


int acco = 0;
int x, y;

void new_account();
void Deposit();
void transfer();
void information();
void Logout();
void options();
void isiEwallet();
void editAcc(int a);
void pulsa(struct acc_type *account);

//Program Utama
int main()
{
    struct acc_type *acc;
    char option;
    while(1)
    {
       if(acco == 0){
        printf("\nSelamat datang di aplikasi mobile banking\n");
        new_account();
       }
       display_options();
       printf("Masukan salah satu opsi (1/2/3/4/5/6) ");
       printf("to continue : ");

        option = getch();
        printf("%c \n", option);
        switch(option)
        {
          case '1': new_account();
                    break;
          case '2': Deposit();
                    break;
          case '3': transfer();
                    break;
          case '4': information();
                    break;
          case '5': isiEwallet();
                    break;
          case '6': system("cls");
                    printf("Akun nomor berapa yang ingin diedit :");
                    scanf("%d", &y);
                    editAcc(y);
                    break;
          case '7': system("cls");
                    printf("Akun nomor berapa yang ingin mengisikan pulsa :");
                    scanf("%d", &y);
                    acc = &account[y-1];
                    pulsa(acc);
                    break;
          case '8': return 0;
          case '9': system("cls");
                    break;
          default : system("cls");
                    printf("Masukan salah satu opsi");
                    printf("(1/2/3/4/5/6/7/8/9) untuk melanjutkan proses \n ");
                    break;
        }
    }
    return 0;
}

//Fungsi untuk display pilihan menu utama

void display_options()
{
    printf("\n1. Buat akun baru\n");
    printf("2. Setor tunai\n");
    printf("3. Transfer uang \n");
    printf("4. Informasi akun \n");
    printf("5. Top up E-Wallet \n");
    printf("6. Edit Akun \n");
    printf("7. Isi Pulsa \n");
    printf("8. Log out \n");
    printf("9. Clear the screen\n");
}

//Fungsi membat akun baru

void new_account()
{
   acco++;
   char bank_name[20];
   char acc_email[40];
   char acc_pass[20];
   char bank_branch[20];
   char acc_holder_name[40];
   int acc_number = acco;
   char acc_holder_address[100];
   float available_balance = 0;
   char rekening[20];

   fflush(stdin);
   printf("\nPembuatan akun ke-%d", acc_number);
   printf("\nNo. Rekening                     : ");
   gets(rekening);
   printf("\nEmail                            : ");
   gets(acc_email);
   printf("\nKata sandi                       : ");
   gets(acc_pass);
   printf("\nMasukan nama bank                : ");
   gets(bank_name);
   printf("\nMasukan cabang bank              : ");
   gets(bank_branch);
   printf("\nMasukan nama pemilik akun        : ");
   gets(acc_holder_name);
   printf("\nMasukan alamat pemilik akun      : ");
   gets(acc_holder_address);

   strcpy(account[acc_number-1].acc_email,acc_email);
   strcpy(account[acc_number-1].acc_pass,acc_pass);
   strcpy(account[acc_number-1].bank_name,bank_name);
   strcpy(account[acc_number-1].bank_branch,bank_branch);
   strcpy(account[acc_number-1].acc_holder_name, acc_holder_name);
   account[acc_number-1].acc_number=acc_number;
   strcpy(account[acc_number-1].acc_holder_address, acc_holder_address);
   account[acc_number-1].available_balance=available_balance;
   strcpy(account[acc_number-1].nomorRekening ,rekening);
   account[acc_number-1].transferBerapa = 0;

   printf("\n Akun telah berhasil dibuat \n\n");
   printf("Nomor Rekening         : %s \n", account[acc_number-1].nomorRekening);
   printf("Email                  : %s \n", account[acc_number-1].acc_email);
   printf("Kata sandi             : ");
   for(x = 0; x<strlen(account[acc_number-1].acc_pass); x++){
        printf("*");
   }
   printf("\nNama bank              : %s \n", account[acc_number-1].bank_name);
   printf("Cabang bank            : %s \n", account[acc_number-1].bank_branch);
   printf("Nama pemilik akun      : %s \n", account[acc_number-1].acc_holder_name);
   printf("Nomor akun             : %d \n", account[acc_number-1].acc_number);
   printf("Alamat pemilik akun    : %s \n", account[acc_number-1].acc_holder_address);
   printf("Jumlah saldo           : Rp.%.2f \n", account[acc_number-1].available_balance);

}

// Fungsi menunjukan informasi akun

void information()
{
     system("cls");
     register int num_acc = 0;
     while(strlen(account[num_acc].bank_name)>0)
     {
        printf("Nomor Rekening         : %s \n", account[num_acc].nomorRekening);
        printf("Email                  : %s \n", account[num_acc].acc_email);
        printf("Kata sandi             : ");
        for(x = 0; x<strlen(account[num_acc].acc_pass); x++){
            printf("*");
        }
         printf("\nNama bank              : %s \n" , account[num_acc].bank_name);
         printf("Cabang bank              : %s \n" , account[num_acc].bank_branch);
         printf("Nama pemilik akun        : %s \n" , account[num_acc].acc_holder_name);
         printf("Nomor akun               : %d \n" , account[num_acc].acc_number);
         printf("Alamat pemilik akun      : %s \n" , account[num_acc].acc_holder_address);
         printf("Jumlah saldo             : Rp.%.2f \n" , account[num_acc].available_balance);
         printf("\nSejarah Transfer\n");
         printf("------------------------------\n");
         printf("No\tIncome/Outcome\tTujuan/Asal instansi\tNomor Rekening/Nomor Handphone\tJumlah uang\n");
         if(account[num_acc].transferBerapa == 0){
            printf("Tidak ada sejarah tranfer\n");
         }else {
            for(x = 0;x<account[num_acc].transferBerapa;x++){
                printf("%d\t%s\t%s\t%s\t\t%.2f\n", x+1, account[num_acc].his[x].come, account[num_acc].his[x].tujuanBank, account[num_acc].his[x].tujuan, account[num_acc].his[x].uang);
            }
         }
         printf("\n");
         num_acc++;
     }
}

// Fungsi untuk setor tunai

void Deposit()
{
   system("cls");
   auto int acc_no;
   float withdraw_money;
   char tujuanRekening[20];
   char bank[20];
   printf("Masukan nomor akun untuk melakukan setor tunai (1-10):");
   scanf("%d",&acc_no);
   printf("\nMasukkan dari Bank mana untuk stor tunai: ");
   scanf("%s", bank);
   printf("\nMasukkan Asal no. rekening: ");
   scanf("%s", tujuanRekening);
   printf("\nJumlah saldo akun ke-%d adalah Rp.%.2f\n", acc_no, account[acc_no-1].available_balance);
   printf("\nMasukkan berapa uang yang ingin dimasukkan :");
   scanf("%f",&withdraw_money);
   while (acc_no=account[acc_no-1].acc_number)
   {

         account[acc_no-1].his[account[acc_no-1].transferBerapa].uang = withdraw_money;
         strcpy(account[acc_no-1].his[account[acc_no-1].transferBerapa].tujuan,tujuanRekening);
         strcpy(account[acc_no-1].his[account[acc_no-1].transferBerapa].tujuanBank,bank);
         strcpy(account[acc_no-1].his[account[acc_no-1].transferBerapa].come,"Transfer: Income");
         account[acc_no-1].available_balance = account[acc_no-1].available_balance+withdraw_money;
         printf("\nJumlah saldo akun ke-%d adalah %.2f \n", acc_no, account[acc_no-1].available_balance);
         account[acc_no-1].transferBerapa = account[acc_no-1].transferBerapa + 1;
         break;
   }acc_no++;
}

// Fungsi untuk transfer uang

void transfer()
{
   system("cls");
   auto int acc_no;
   float withdraw_money;
   char tujuanRekening[20];
   char bank[20];
   printf("Masukan nomor akun untuk melakukan penarikan saldo (1-10):");
   scanf("%d",&acc_no);
   printf("\nMasukkan tujuan Bank: ");
   scanf("%s", &bank);
   printf("\nMasukkan tujuan no. rekening: ");
   scanf("%s", &tujuanRekening);
   printf("\nJumlah saldo akun ke-%d adalah Rp.%.2f \n", acc_no, account[acc_no-1].available_balance);
   while(1){
       printf("\nMasukan jumlah uang yang ingin ditransfer :");
       scanf("%f",&withdraw_money);
       if(withdraw_money > account[acc_no-1].available_balance){
            printf("Tidak bisa transfer karena uang transfer lebih besar\n");
       } else {
            break;
       }
   }
   while (acc_no=account[acc_no-1].acc_number)
   {

         account[acc_no-1].his[account[acc_no-1].transferBerapa].uang = withdraw_money;
         strcpy(account[acc_no-1].his[account[acc_no-1].transferBerapa].tujuan,tujuanRekening);
         strcpy(account[acc_no-1].his[account[acc_no-1].transferBerapa].tujuanBank,bank);
         strcpy(account[acc_no-1].his[account[acc_no-1].transferBerapa].come,"Transfer: Outcome");
         account[acc_no-1].available_balance = account[acc_no-1].available_balance-withdraw_money;
         printf("\nJumlah saldo akun ke-%d adalah Rp.%.2f \n", acc_no, account[acc_no-1].available_balance);
         account[acc_no-1].transferBerapa = account[acc_no-1].transferBerapa + 1;
         break;
   }acc_no++;
}

//Fungsi untuk isi Ewallet

void isiEwallet()
{
   system("cls");
   auto int acc_no;
   char money;
   float withdraw_money;
   char tujuanRekening[20];
   char bank[20];
   printf("Masukan nomor akun untuk melakukan penarikan saldo (1-10):");
   scanf("%d",&acc_no);
   do{
       printf("1. Gopay\n");
       printf("2. OVO\n");
       printf("3. Flazz\n");
       printf("4. Emoney\n");
       printf("\nMasukkan tujuan E-Wallet: ");
       money = getch();
       printf("%c \n", money);
       switch(money){
            case '1': strcpy(bank, "Gopay");
                      x = 0;
                      break;
            case '2': strcpy(bank, "OVO");
                      x = 0;
                      break;
            case '3': strcpy(bank, "Flazz");
                      x = 0;
                      break;
            case '4': strcpy(bank, "Emoney");
                      x =  0;
                      break;
            default : printf("Error");
                      x = 1;
                      break;
       }
   }while(x != 0);
   printf("\nMasukkan tujuan no. handphone tujuan: ");
   scanf("%s", &tujuanRekening);
   printf("\nJumlah saldo akun ke-%d adalah Rp.%.2f \n", acc_no, account[acc_no-1].available_balance);
   while(1){
       printf("\nMasukan jumlah uang yang ingin ditransfer :");
       scanf("%f",&withdraw_money);
       if(withdraw_money > account[acc_no-1].available_balance){
            printf("Tidak bisa transfer karena uang transfer lebih besar\n");
       } else {
            break;
       }
   }
   while (acc_no=account[acc_no-1].acc_number)
   {

         account[acc_no-1].his[account[acc_no-1].transferBerapa].uang = withdraw_money;
         strcpy(account[acc_no-1].his[account[acc_no-1].transferBerapa].tujuan,tujuanRekening);
         strcpy(account[acc_no-1].his[account[acc_no-1].transferBerapa].tujuanBank,bank);
         strcpy(account[acc_no-1].his[account[acc_no-1].transferBerapa].come,"E-wallet: Outcome");
         account[acc_no-1].available_balance = account[acc_no-1].available_balance-withdraw_money;
         printf("\nJumlah saldo akun ke-%d adalah Rp.%.2f \n", acc_no, account[acc_no-1].available_balance);
         account[acc_no-1].transferBerapa = account[acc_no-1].transferBerapa + 1;
         break;
   }acc_no++;
}

//Fungsi untuk edit akun

void editAcc(int a){
    system("cls");
    char z;
    char acc_email[40];
    char acc_pass[20];
    char acc_holder_name[40];
    char acc_holder_address[100];
    printf("1. Nama akun pemilik\n");
    printf("2. Email\n");
    printf("3. Kata sandi\n");
    printf("4. Alamat pemilik akun\n");
    printf("Masukkan angka bagian yang ingin diubah: ");
    z = getch();
    printf("%c \n", z);

    switch(z){
    case '1':
        printf("\nMasukan nama baru pemilik akun        : ");
        scanf("%s", &acc_holder_name);
        strcpy(account[a-1].acc_holder_name, acc_holder_name);
        break;

    case '2':
        printf("\nMasukan Email baru pemilik akun        : ");
        scanf("%s", &acc_email);
        strcpy(account[a-1].acc_email,acc_email);
        break;

    case '3':
        printf("\nMasukan Kata Sandi baru pemilik akun        : ");
        scanf("%s", &acc_pass);
        strcpy(account[a-1].acc_pass,acc_pass);
        break;

    case '4':
        printf("\nMasukan Alamat baru pemilik akun        : ");
        scanf("%s", &acc_holder_address);
        strcpy(account[a-1].acc_holder_address, acc_holder_address);
        break;
    }

    printf("\nPerubahan berhasil\n\n");

    printf("Nomor Rekening         : %s\n", account[a-1].nomorRekening);
    printf("Email                  : %s \n", account[a-1].acc_email);
    printf("Kata sandi             : ");
    for(x = 0; x<strlen(account[x].acc_pass); x++){
        printf("*");
    }
    printf("\nNama bank              : %s \n" , account[a-1].bank_name);
    printf("Cabang bank              : %s \n" , account[a-1].bank_branch);
    printf("Nama pemilik akun        : %s \n" , account[a-1].acc_holder_name);
    printf("Nomor akun               : %d \n" , account[a-1].acc_number);
    printf("Alamat pemilik akun      : %s \n" , account[a-1].acc_holder_address);
    printf("Jumlah saldo             : Rp.%f \n" , account[a-1].available_balance);

}

//Fungsi untuk isi Pulsa

void pulsa(struct acc_type *account){
   system("cls");
   char pilihan[4][20] = {"1. Indosat", "2. Telkomsel", "3. XL", "4. 3(Three)"};
   char money;
   char pilih;
   float withdraw_money;
   char tujuanRekening[20];
   char bank[20];
   do{
       for(x = 0; x<4; x++){
        printf("%s\n", pilihan[x]);
       }
       printf("\nMasukkan pilihan operator: ");
       money = getch();
       printf("%c \n", money);
       switch(money){
            case '1': strcpy(bank, "Indosat");
                      x = 0;
                      break;
            case '2': strcpy(bank, "Telkomsel");
                      x = 0;
                      break;
            case '3': strcpy(bank, "XL");
                      x = 0;
                      break;
            case '4': strcpy(bank, "3(Three)");
                      x =  0;
                      break;
            default : printf("Error");
                      x = 1;
                      break;
       }
   }while(x != 0);
   printf("\nMasukkan No. Handphone: ");
   scanf("%s", &tujuanRekening);
   printf("\nJumlah saldo akun ke-%d adalah %f \n", account->acc_number, account->available_balance);
   while(1){
       printf("\n1. Rp. 15.000");
       printf("\n2. Rp. 25.000");
       printf("\n3. Rp. 50.000");
       printf("\n4. Rp. 75.000");
       printf("\n5. Rp. 100.000");
       printf("\n6. Rp. 150.000");
       printf("\nMasukan jumlah pulsa yang ingin diisi :");
       pilih = getch();
       printf("%c \n", pilih);
       switch(pilih){
            case '1': withdraw_money = 15000;
                      x = 0;
                      break;
            case '2': withdraw_money = 25000;
                      x = 0;
                      break;
            case '3': withdraw_money = 50000;
                      x = 0;
                      break;
            case '4': withdraw_money = 75000;
                      x =  0;
                      break;
            case '5': withdraw_money = 100000;
                      x =  0;
                      break;
            case '6': withdraw_money = 150000;
                      x =  0;
                      break;
            default : printf("Error");
                      x = 1;
                      break;
       }
       if(withdraw_money > account->available_balance){
            printf("Tidak bisa transfer karena uang transfer lebih besar\n");
       } else if(x != 0){
            printf("Terjadi Kesalahan");
       } else {
            break;
       }
   }

    account->his[account->transferBerapa].uang = withdraw_money;
    strcpy(account->his[account->transferBerapa].tujuan,tujuanRekening);
    strcpy(account->his[account->transferBerapa].tujuanBank,bank);
    strcpy(account->his[account->transferBerapa].come,"Isi Pulsa");
    account->available_balance = (account->available_balance)-withdraw_money;
    printf("\nJumlah saldo akun ke-%d adalah Rp.%.2f \n", account->acc_number, account->available_balance);
    account->transferBerapa = account->transferBerapa + 1;
}
