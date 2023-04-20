// Don't modify this file as it will be overwritten.
//
#include "IDL_UserDataType.h"

UserDataType::UserDataType(const UserDataType &IDL_s){
  src = IDL_s.src;
  dest = IDL_s.dest;
}

UserDataType& UserDataType::operator= (const UserDataType &IDL_s){
  if (this == &IDL_s) return *this;
  src = IDL_s.src;
  dest = IDL_s.dest;
  return *this;
}

void UserDataType::Marshal(CDR *cdr) const {
  cdr->PutString(src);
  cdr->PutString(dest);
}

void UserDataType::UnMarshal(CDR *cdr){
  {
    char *IDL_str;
    cdr->GetString(IDL_str);
    if(src != NULL )
    {
        delete src;
        src = NULL;
    }
    src = IDL_str;
  }
  {
    char *IDL_str;
    cdr->GetString(IDL_str);
    if(dest != NULL )
    {
        delete dest;
        dest = NULL;
    }
    dest = IDL_str;
  }
}

