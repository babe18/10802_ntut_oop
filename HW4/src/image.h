#ifndef IMAGE_H
#define IMAGE_H

class Image{
public:
  Image():
    imageSrc(""),top("0px"),left("0px"){
  }

  std::string render(){
    return "<img src='"+imageSrc+"' style='top:"+top+";left:"+left+";position:absolute;'/>";
  }

  void setPosition(std::string top, std::string left){
    this->top=top;
    this->left=left;
  }

  void setSrc(std::string imageSrc){
    this->imageSrc=imageSrc;
  }

private:
  std::string imageSrc;
  std::string top;
  std::string left;
};

#endif
