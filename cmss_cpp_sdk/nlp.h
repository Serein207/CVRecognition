#ifndef __CMSS_AI_NLP_H__
#define __CMSS_AI_NLP_H__

#include "base/base.h"
#include <vector>
#include "item.h"

namespace cmssai {

    class Nlp: public AipBase
    {
    public:			
		std::string _sentiment_wb = "https://api-wuxi-1.cmecloud.cn:8443/api/nlp/v1/sentiment/wb";
		std::string _emotion = "https://api-wuxi-1.cmecloud.cn:8443/api/nlp/v1/emotion";
		std::string _industry = "https://api-wuxi-1.cmecloud.cn:8443/api/nlp/v1/industry";
		std::string _segmentation = "https://api-wuxi-1.cmecloud.cn:8443/api/nlp/v1/segmentation";
		std::string _keywords = "https://api-wuxi-1.cmecloud.cn:8443/api/nlp/v1/keywords";
		std::string _sentiment_news = "https://api-wuxi-1.cmecloud.cn:8443/api/nlp/v1/sentiment/news";
		std::string _sentiment_forum = "https://api-wuxi-1.cmecloud.cn:8443/api/nlp/v1/sentiment/forum";
		std::string _convertdoc = "https://api-wuxi-1.cmecloud.cn:8443/api/nlp/v1/convertdoc";
		std::string _entity = "https://api-wuxi-1.cmecloud.cn:8443/api/nlp/v1/entity";
		std::string _filter = "https://api-wuxi-1.cmecloud.cn:8443/api/nlp/v1/filter";
		std::string _location = "https://api-wuxi-1.cmecloud.cn:8443/api/nlp/v1/location";
		std::string _viewpoint = "https://api-wuxi-1.cmecloud.cn:8443/api/nlp/v1/viewpoint";
		std::string _sentiment_ng = "https://api-wuxi-1.cmecloud.cn:8443/api/nlp/v1/sentiment/negative";
		std::string _announcement = "https://api-wuxi-1.cmecloud.cn:8443/api/nlp/v1/announcement-ie";
		std::string _rumor = "https://api-wuxi-1.cmecloud.cn:8443/api/nlp/v1/rumor";
		std::string _theme_matcher = "https://api-wuxi-1.cmecloud.cn:8443/api/nlp/v1/theme-matcher";
		std::string _text_similarity = "https://api-wuxi-1.cmecloud.cn:8443/api/nlp/v1/text-similarity";
		
        Nlp(const std::string & ak, const std::string & sk): AipBase(ak, sk)
        {
        }
        
		std::string convertdoc(std::string const & filename)
        {
            std::map<std::string, std::string> data;
			data["auditFile"] = filename;
            std::string result =
                this->request(_convertdoc, null, data, null);
            return result;
        }
		
		std::string sentiment_wb(std::vector<cmssai::Item> & params)
        {
            std::map<std::string, std::string> data;
			std::stringstream items;
			items<<"[";
			for(int i = 0; i < params.size(); i++){
				std::string p = params[i].getItem();
				items<<p;
			}
			items<<"]";
			data["items"] = items.str();
			//std::cout<<data["items"]<<std::endl;
            std::string result =
                this->request(_sentiment_wb, null, data, null);
            return result;
        }
		
		std::string emotion(std::vector<cmssai::Item> & params)
        {
            std::map<std::string, std::string> data;
			std::stringstream items;
			items<<"[";
			for(int i = 0; i < params.size(); i++){
				std::string p = params[i].getItem();
				items<<p;
			}
			items<<"]";
			data["items"] = items.str();
			//std::cout<<data["items"]<<std::endl;
            std::string result =
                this->request(_emotion, null, data, null);
            return result;
        }
		
		std::string industry(std::vector<cmssai::Item> & params)
        {
            std::map<std::string, std::string> data;
			std::stringstream items;
			items<<"[";
			for(int i = 0; i < params.size(); i++){
				std::string p = params[i].getItem();
				items<<p;
			}
			items<<"]";
			data["items"] = items.str();
			//std::cout<<data["items"]<<std::endl;
            std::string result =
                this->request(_industry, null, data, null);
            return result;
        }
		
		std::string segmentation(std::vector<cmssai::Item> & params)
        {
            std::map<std::string, std::string> data;
			std::stringstream items;
			items<<"[";
			for(int i = 0; i < params.size(); i++){
				std::string p = params[i].getItem();
				items<<p;
			}
			items<<"]";
			data["items"] = items.str();
			//std::cout<<data["items"]<<std::endl;
            std::string result =
                this->request(_segmentation, null, data, null);
            return result;
        }
		
		std::string keywords(std::vector<cmssai::Item> & params)
        {
            std::map<std::string, std::string> data;
			std::stringstream items;
			items<<"[";
			for(int i = 0; i < params.size(); i++){
				std::string p = params[i].getItem();
				items<<p;
			}
			items<<"]";
			data["items"] = items.str();
			//std::cout<<data["items"]<<std::endl;
            std::string result =
                this->request(_keywords, null, data, null);
            return result;
        }
		
		std::string sentiment_news(std::vector<cmssai::Item> & params)
        {
            std::map<std::string, std::string> data;
			std::stringstream items;
			items<<"[";
			for(int i = 0; i < params.size(); i++){
				std::string p = params[i].getItem();
				items<<p;
			}
			items<<"]";
			data["items"] = items.str();
			//std::cout<<data["items"]<<std::endl;
            std::string result =
                this->request(_sentiment_news, null, data, null);
            return result;
        }
		
		std::string sentiment_forum(std::vector<cmssai::Item> & params)
        {
            std::map<std::string, std::string> data;
			std::stringstream items;
			items<<"[";
			for(int i = 0; i < params.size(); i++){
				std::string p = params[i].getItem();
				items<<p;
			}
			items<<"]";
			data["items"] = items.str();
			//std::cout<<data["items"]<<std::endl;
            std::string result =
                this->request(_sentiment_forum, null, data, null);
            return result;
        }
		
		std::string filter(std::vector<cmssai::Item> & params)
        {
            std::map<std::string, std::string> data;
			std::stringstream items;
			items<<"[";
			for(int i = 0; i < params.size(); i++){
				std::string p = params[i].getItem();
				items<<p;
			}
			items<<"]";
			data["items"] = items.str();
			//std::cout<<data["items"]<<std::endl;
            std::string result =
                this->request(_filter, null, data, null);
            return result;
        }
		
		std::string entity(std::vector<cmssai::Item> & params)
        {
            std::map<std::string, std::string> data;
			std::stringstream items;
			items<<"[";
			for(int i = 0; i < params.size(); i++){
				std::string p = params[i].getItem();
				items<<p;
			}
			items<<"]";
			data["items"] = items.str();
			//std::cout<<data["items"]<<std::endl;
            std::string result =
                this->request(_entity, null, data, null);
            return result;
        }
		
		std::string location(std::vector<cmssai::Item> & params)
        {
            std::map<std::string, std::string> data;
			std::stringstream items;
			items<<"[";
			for(int i = 0; i < params.size(); i++){
				std::string p = params[i].getItem();
				items<<p;
			}
			items<<"]";
			data["items"] = items.str();
			//std::cout<<data["items"]<<std::endl;
            std::string result =
                this->request(_location, null, data, null);
            return result;
        }
		
		std::string viewpoint(std::vector<cmssai::Item> & params)
        {
            std::map<std::string, std::string> data;
			std::stringstream items;
			items<<"[";
			for(int i = 0; i < params.size(); i++){
				std::string p = params[i].getItem();
				items<<p;
			}
			items<<"]";
			data["items"] = items.str();
			//std::cout<<data["items"]<<std::endl;
            std::string result =
                this->request(_viewpoint, null, data, null);
            return result;
        }
		
		std::string sentiment_ng(std::vector<cmssai::Item> & params)
        {
            std::map<std::string, std::string> data;
			std::stringstream items;
			items<<"[";
			for(int i = 0; i < params.size(); i++){
				std::string p = params[i].getItem();
				items<<p;
			}
			items<<"]";
			data["items"] = items.str();
			//std::cout<<data["items"]<<std::endl;
            std::string result =
                this->request(_sentiment_ng, null, data, null);
            return result;
        }
		
		std::string announcement(std::vector<cmssai::Item> & params)
        {
            std::map<std::string, std::string> data;
			std::stringstream items;
			items<<"[";
			for(int i = 0; i < params.size(); i++){
				std::string p = params[i].getItem();
				items<<p;
			}
			items<<"]";
			data["items"] = items.str();
			//std::cout<<data["items"]<<std::endl;
            std::string result =
                this->request(_announcement, null, data, null);
            return result;
        }
		
		std::string rumor(std::vector<cmssai::Item> & params)
        {
            std::map<std::string, std::string> data;
			std::stringstream items;
			items<<"[";
			for(int i = 0; i < params.size(); i++){
				std::string p = params[i].getItem();
				items<<p;
			}
			items<<"]";
			data["items"] = items.str();
			//std::cout<<data["items"]<<std::endl;
            std::string result =
                this->request(_rumor, null, data, null);
            return result;
        }
		
		std::string theme_matcher(std::vector<cmssai::Item> & params)
        {
            std::map<std::string, std::string> data;
			std::stringstream items;
			items<<"[";
			for(int i = 0; i < params.size(); i++){
				std::string p = params[i].getItem();
				items<<p;
			}
			items<<"]";
			data["items"] = items.str();
			//std::cout<<data["items"]<<std::endl;
            std::string result =
                this->request(_theme_matcher, null, data, null);
            return result;
        }
		
		std::string text_similarity(std::vector<cmssai::Item> & params)
        {
            std::map<std::string, std::string> data;
			std::stringstream items;
			items<<"[";
			for(int i = 0; i < params.size(); i++){
				std::string p = params[i].getItem();
				items<<p;
			}
			items<<"]";
			data["items"] = items.str();
			//std::cout<<data["items"]<<std::endl;
            std::string result =
                this->request(_text_similarity, null, data, null);
            return result;
        }
                
    };

}
#endif
