#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

#include <openssl/bn.h>
#include <openssl/obj_mac.h>
#include <openssl/ec.h>

void createKeypair(EC_KEY **key){
    *key = EC_KEY_new();
    EC_GROUP *ecgroup = EC_GROUP_new_by_curve_name(NID_X9_62_prime256v1);
    EC_KEY_set_group(*key, ecgroup);
    EC_KEY_generate_key(*key);
}

/*
void signData(EC_KEY **key, const unsigned char* data, ){
    ECDSA_SIG *signature = ECDSA_do_sign(data, strlen((char*)data), *key);
}
*/

/*
    const BIGNUM *pr = NULL;
    const BIGNUM *ps = NULL;
    
    ECDSA_SIG_get0(signature, &pr, &ps);

    BIGNUM *tr = BN_dup(pr);
    BIGNUM *ts = BN_dup(ps);

    ECDSA_SIG *newSig = ECDSA_SIG_new();
    ECDSA_SIG_set0(newSig, tr, ts);

    int success = ECDSA_do_verify(hash, strlen((char*)hash), newSig, eckey);
    if(success != 1){
        cout << "Failed to verify sig!" << endl;
        return -1;
    }

    cout << "Verified sig!" << endl;

    EC_GROUP_free(ecgroup);

    EC_KEY_free(eckey);
*/

int main(){
    EC_KEY *key;
    createKeypair(&key);
    
    const BIGNUM *keyNum = EC_KEY_get0_private_key(key);
    cout << BN_bn2hex(keyNum) << endl;

    EC_KEY_free(key);
    return(0);
}