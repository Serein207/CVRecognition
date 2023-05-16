#ifndef __CMSS_AI_ITEM_H__
#define __CMSS_AI_ITEM_H__

#include <string>
#include <sstream>

namespace cmssai{
	class Item{
	public:
		std::string textId;
		std::string text;
		std::string title;
		std::string content;
		std::string type;
		std::string htmlText;
		std::string initial;
		std::string source;
		std::string target;
		std::string keyString;
		std::string modelType;
		
		Item()
		{
		}
		
		void setTextId(const std::string & textId){
			this->textId = textId;
		}
		
		void setText(const std::string & text){
			this->text = text;
		}
		
		void setTitle(const std::string & title){
			this->title = title;
		}
		
		void setContent(const std::string & content){
			this->content = content;
		}
		
		void setType(const std::string & type){
			this->type = type;
		}
		
		void setHtmlText(const std::string & htmlText){
			this->htmlText = htmlText;
		}
		
		void setInitial(const std::string & initial){
			this->initial = initial;
		}
		
		void setSource(const std::string & source){
			this->source = source;
		}
		
		void setTarget(const std::string & target){
			this->target = target;
		}
		
		void setKeyString(const std::string & keyString){
			this->keyString = keyString;
		}
		
		void setModelType(const std::string & modelType){
			this->modelType = modelType;
		}
		
		std::string getItem()
		{
			std::stringstream ss;
			if(!this->textId.empty()){
				ss << "{\"textId\":\"" << textId << "\"";
			}
			if(!this->text.empty()){
				ss<< ",\"text\":\""<<text<<"\"";
			}
			if(!this->title.empty()){
				ss<< ",\"title\":\""<<title<<"\"";
			}
			
			if(!this->content.empty()){
				ss<< ",\"content\":\""<<content<<"\"";
			}
			
			if(!this->type.empty()){
				ss<< ",\"type\":\""<<type<<"\"";
			}
			
			if(!this->htmlText.empty()){
				ss<< ",\"htmlText\":\""<<htmlText<<"\"";
			}
			
			if(!this->initial.empty()){
				ss<< ",\"initial\":\""<<initial<<"\"";
			}
			
			if(!this->source.empty()){
				ss<< ",\"source\":\""<<source<<"\"";
			}
			
			if(!this->target.empty()){
				ss<< ",\"target\":\""<<target<<"\"";
			}
			
			if(!this->keyString.empty()){
				ss<< ",\"keyString\":\""<<keyString<<"\"";
			}
			
			if(!this->modelType.empty()){
				ss<< ",\"modelType\":\""<<modelType<<"\"";
			}
			ss<<"}";
			return ss.str();
		}
	};
	
}

#endif