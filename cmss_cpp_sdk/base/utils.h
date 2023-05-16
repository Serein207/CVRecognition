#ifndef __CMSS_AI_UTILS_H__
#define __CMSS_AI_UTILS_H__

#include <string>
#include <fstream>
#include <ctype.h>
#include <openssl/evp.h>
#include <openssl/hmac.h>
#include <algorithm>
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <vector>

const int __BCE_VERSION__ = 1;
const int __BCE_EXPIRE__ = 1800;

namespace cmssai {
    
    template<class CharT, class Traits, class Allocator>
    std::basic_istream<CharT, Traits>& getall(std::basic_istream<CharT, Traits>& input,
                                              std::basic_string<CharT, Traits, Allocator>& str) {
        std::ostringstream oss;
        oss << input.rdbuf();
        str.assign(oss.str());
        return input;
    }
    
    inline int get_file_content(const char *filename, std::string* out) {
        std::ifstream in(filename, std::ios::in | std::ios::binary);
        if (in) {
            getall(in, *out);
            return 0;
        } else {
            return -1;
        }
    }
    
    inline std::string to_upper(std::string src)
    {
        std::transform(src.begin(), src.end(), src.begin(), toupper);
        return src;
    }
    
    
    inline std::string to_lower(std::string src)
    {
        std::transform(src.begin(), src.end(), src.begin(), tolower);
        return src;
    }
    
    inline std::string to_hex(unsigned char c, bool lower = false)
    {
        const std::string hex = "0123456789ABCDEF";
        
        std::stringstream ss;
        ss << hex[c >> 4] << hex[c & 0xf];
        
        return lower ? to_lower(ss.str()) : ss.str();
    }
    
    inline time_t now()
    {
        return time(NULL);
    }
    
    std::string utc_time(time_t timestamp)
    {
        struct tm result_tm;
        char buffer[32];
        
#ifdef _WIN32
        localtime_s(&result_tm, &timestamp);
#else
        localtime_r(&timestamp, &result_tm);
#endif
        
        size_t size = strftime(buffer, 32, "%Y-%m-%dT%H:%M:%SZ", &result_tm);
        
        return std::string(buffer, size);
    }
    
	/**
	* 对url进行处理，如果url中有查询参数，会把查询参数都放到params这个map里面
	*/
    void url_parse(const std::string & url, std::map<std::string, std::string> & params)
    {
        int pos = (int)url.find("?");
        if (pos != -1)
        {
            int key_start = pos + 1,
            key_len = 0,
            val_start = 0;
            for (int i = key_start; i <= (int)url.size(); ++i)
            {
                switch (url[i])
                {
                    case '=':
                        key_len = i - key_start;
                        val_start = i + 1;
                        break;
                    case '\0':
                    case '&':
                        if (key_len != 0)
                        {
                            params[url.substr(key_start, key_len)] = url.substr(val_start, i - val_start);
                            key_start = i + 1;
                            key_len = 0;
                        }
                        break;
                    default:
                        break;
                }
            }
        }
    }
    
    std::string url_encode(const std::string & input, bool encode_slash=true)
    {
        std::stringstream ss;
        const char *str = input.c_str();
        
        for (uint32_t i = 0; i < input.size(); i++)
        {
            unsigned char c = str[i];
            if (isalnum(c) || c == '_' || c == '-' || c == '~' || c == '.' || (!encode_slash && c == '/'))
            {
                ss << c;
            }
            else
            {
                ss << "%" << to_hex(c);
            }
        }
        
        return ss.str();
    }
    
    std::string canonicalize_params(std::map<std::string, std::string> & params)
    {
        std::vector<std::string> v;
        v.reserve(params.size());
        
        for (auto & it : params) {
            v.push_back(url_encode(it.first) + "=" + url_encode(it.second));
        }
        std::sort(v.begin(), v.end());
        
        std::string result;
        for (auto & it : v)
        {
            result.append((result.empty() ? "" : "&") + it);
        }
        return result;
    }
        
	/**
	* 从请求的url里面把请求的path截出来
	*/
    std::string get_path(const std::string & url)
    {
        int path_start = (int)url.find('/', url.find("://") + 3);
        int path_end = (int)url.find('?');
        path_end = path_end == -1 ? (int)url.size() : path_end;
        
        return url.substr(path_start, path_end - path_start);
    }
    	
	std::string sha256(const std::string & src){
		char buf[100];
		unsigned char hash[SHA256_DIGEST_LENGTH];
		SHA256_CTX sha256;
		SHA256_Init(&sha256);
		SHA256_Update(&sha256, src.c_str(), src.size());
		SHA256_Final(hash, &sha256);
		std::string NewString = "";
		for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
		{
			sprintf(buf,"%02x",hash[i]);
			NewString = NewString + buf;
		}
        return NewString;
	}
	
	std::string hmacsha1(const std::string & src, const std::string & sk){
		unsigned char* result;
		unsigned int len = 20;
		result = (unsigned char*)malloc(sizeof(char) * len);
		HMAC_CTX* ctx = HMAC_CTX_new();
		HMAC_CTX_reset(ctx);
		
		
		
		HMAC_Init_ex(ctx, sk.data(), strlen(sk.data()), EVP_sha1(), NULL);
		HMAC_Update(ctx, reinterpret_cast<const unsigned char *>(src.data()), src.size());
		HMAC_Final(ctx, result, &len);
		HMAC_CTX_free(ctx);
		
		std::stringstream ss;
		for(int i = 0; i < len; i++){
			ss << to_hex(result[i], true);
		}
		
		free(result);
		return ss.str();
	}
	
	std::string getuuid(){
		srand(time(NULL));
		std::stringstream ss;
		for(int i = 0; i < 32; i++){
			int k = rand() % 2;
			if(k == 0){
				ss<<(char)('a' + rand() % 26);
			}
			else {
				ss<<('0' + rand() % 10);
			}
		}
		return ss.str();

	}
    void sign(
              std::string method,
              std::string & url,
              std::map<std::string, std::string> & params,
              std::map<std::string, std::string> & headers,
              std::string & ak,
              std::string & sk)
    {
        url_parse(url, params);
		
        std::string timestamp = utc_time(now());
        		
		std::stringstream querystring;
		std::string randstr = getuuid();
		querystring<<"AccessKey="<<ak<<"&SignatureMethod=HmacSHA1&SignatureNonce="<<randstr<<"&SignatureVersion=V2.0&Timestamp=" <<url_encode(utc_time(now()), true);
		
        std::string val = querystring.str();
        std::string shastring = sha256(val);
        
        querystring.str("");
        querystring << to_upper(method) << '\n' << url_encode(get_path(url), true)
        << '\n' << shastring;
        
        std::string signature = hmacsha1(querystring.str(), "BC_SIGNATURE&" + sk);
		params["AccessKey"] = ak;
		params["SignatureMethod"] = "HmacSHA1";
		params["SignatureNonce"] = randstr;
		params["SignatureVersion"] = "V2.0";
		params["Timestamp"] = utc_time(now());
		params["Signature"] = signature;		
    }
    
}

#endif
