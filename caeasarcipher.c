#include <stdio.h>
#include <ctype.h>   //isdigit fonksiyonu icin
#include <stdlib.h>  // for atoi funct to convert to key an integer
#include <string.h>  // strlen fonksiyonu icin
#include <stdbool.h> // bool false true mevzusu icin

int main(int argc, char *argv[]) // veya int main(int argc, char **argv)
{

    // check for the command line argument
    if (argc == 2)
    {

        // store the key validity
        bool valid_key = false;
        int len = strlen(argv[1]);
        // check of the key validity
        for (int i = 0;i < len; i++)
        {
            if (isdigit(argv[1][i])) // 
            /*yani normalde mesela rakam icerirse 0 döndürücekti ve valid keyi değistiricekti.
            Simdi ise bir tane bile rakam icermezse rakamdan gayrı yani o zaman da ! koyduk ki 1 dondursun*/
            /*Bu kod, argv[1] argümanındaki tüm karakterlerin rakam olup olmadığını kontrol eder.
            Eğer herhangi bir karakter rakam değilse (!isdigit(argv[1][i]) true dönerse), valid_key false yapılır ve döngüden çıkılır.*/
            {
                valid_key = true; // Eğer herhangi bir karakter rakam değilse, false yap
                
            }

            else
            {
                printf("./caesar key:");
                return 1; // tekrar sormasını saglicak;
            }
        }
        // convert key to int
        int key = atoi(argv[1]); // Bu fonksiyon, bir string içindeki sayısal karakterleri bir int (tamsayı) değere dönüştürür.

        // check for upper and lower case letters and use the formula
        if (valid_key == true)
        {

            printf("write your plaintext:");
            char text[500];
            fgets(text, sizeof(text), stdin);
            int lentext = strlen(text);
            for (int i =0 ; i < lentext; i++)
            {
                if (text[i] >= 'A' && text[i] <= 'Z') // buyuk harf mi kucuk harf mi diye isupper fonksiyonunu da kullanabiliriz ctype.h kütüphanesinde
                {
                    /*mesela şöyle diyelim ki text[i] büyük harf tamam mi.
                    Örneğin, 'A' karakteri ASCII tablosunda 65 olarak kodlanmıştır.
                    Dolayısıyla:
                    'A' için: ASCII değeri - 'A' ASCII değeri = 65 - 65 = 0
                    'B' için: ASCII değeri - 'A' ASCII değeri = 66 - 65 = 1*/
                    /*bunu yapariz cunku o text[i]elemaninin kacinci harf oldugunu bilmeliyiz ve
                    ona göre girilen int keye göre ileri kaydırabilecez.*/

                 text[i] = ((text[i] - 'A' + key) % 26) + 'A'; // 'A' = 65 aslında istedigini yaz
                                                                  /*+'A' eklememizin sebebi ise simdi tamam + dan onceki kısımda kac kaydiracagimizi bulduk ama bizim bunu tekrardan ASCII
                                                                  Sistemine dondurmemiz lazımki  C dili bu karakteri bulsun ve yazsın.Ondan aslında 'A' demek 65 demek.
                                                                  'A' Yerine 65 de yazabiliriz her yerde.
                                                                  Aynı şekilde kucuk 'a' icin de bu 97 dir.*/

                    /*simdi burada soyle oldu once kacinci sirada oldugunu bulduk harfin ve sonra keyi ekledik
                     mesela harf A idi bu 0 eder. key de 2 ise 2 sonrası C eder gibisinden
                     ama mesela %26 ise 26 harf icerisinde donmesini saglamak mesela Z denk gelirse eger hemen A ya ya da B ye donsun*/
                }
                else if (text[i] >= 'a' && text[i] <= 'z')
                {
                    // unutma 'a' zaten 97 demek farketmez o yuzden
                    text[i] = ((text[i] - 97 + key) % 26) + 97;
                }
                else
                {
                    text[i];
                }
            }
            printf("ciphertext: %s", text);
        }
    }

    else
    {
        printf(" ./caesar key\n");
        return 1; // terkar sormasını saglicak
    }

    return 0;
}
