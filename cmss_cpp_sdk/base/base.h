#ifndef __CMSS_AI_BASE_H__
#define __CMSS_AI_BASE_H__

#include <memory>
#include <cstring>
#include "http.h"
#include "base64.h"
#include "curl/curl.h"
#include "utils.h"

namespace cmssai {
    static const std::map<std::string, std::string> null;
    class AipBase
    {
    public:
        std::string ak;
        std::string sk;
        HttpClient client;
        AipBase(const std::string & ak, const std::string & sk):
        ak(ak),
        sk(sk)
        {
			
        }
        
		/*
        void setConnectionTimeoutInMillis(int connect_timeout)
        {
            this->client.setConnectTimeout(connect_timeout);
        }
        
        void setSocketTimeoutInMillis(int socket_timeout)
        {
            this->client.setSocketTimeout(socket_timeout);
        }
        
        void setDebug(bool debug)
        {
            this->client.setDebug(debug);
        }
		*/
        
       
        std::string  request(
                            std::string url,
                            std::map<std::string, std::string> const & params,
                            std::string const & data,
                            std::map<std::string, std::string> const & headers)
        {
            std::string response;
            std::string body;
            auto headers_for_sign = headers;
            
            auto temp_params = params;
            
            temp_params["charset"] = "UTF-8";
            
            this->prepare_request(url, temp_params, headers_for_sign);
            
            int status_code = this->client.post(url, &temp_params, data, &headers_for_sign, &response);
            
            if (status_code != CURLcode::CURLE_OK) {
                return "error_request_1";
            }
                        
            return response;
        }
        
		/**
		* url 接口请求地址
		* params 请求的额外参数
		* data 请求参数，data[image]为图片base64编码
		* headers 请求头部
		*/
        std::string request(
                            std::string url,
                            std::map<std::string, std::string> const & params,
                            std::map<std::string, std::string> const & data,
                            std::map<std::string, std::string> const & headers)
        {
            std::string response;
            
            auto headers_for_sign = headers;
            auto temp_params = params;
           			
            this->prepare_request(url, temp_params, headers_for_sign);
            
            int status_code = this->client.post(url, &temp_params, data, &headers_for_sign, &response);
            
            if (status_code != CURLcode::CURLE_OK) {
				return "error_request_2";
            }
            return response;
        }
        
        void prepare_request(std::string url,
                             std::map<std::string, std::string> & params,
                             std::map<std::string, std::string> & headers)
        {			
  			std::string method = "POST";
			sign(method, url, params, headers, ak, sk);	
        }
     
    };
    
}
#endif
