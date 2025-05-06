# 컴퓨터 그래픽스 과제 5 - 소프트웨어 래스터라이저
1. 결과 스크린샷  
![image](https://github.com/user-attachments/assets/fb6c0b53-371f-4ea5-91cb-fe84c869a0f9)
2. 실행 방법  
- zip파일을 다운로드 하고 압축 해제합니다.  
- OpenglViewer.sln 파일을 열어 빌드하시면 됩니다.
   
back-face culling 구현 추가로 해봤고, 삼각형 rasterization 구현시 루프 내부에서 바리센트릭 좌표를 매 픽셀마다 직접 계산하지 않고, 증분 방식으로 효율적으로 갱신했습니다.  
추가로 sphere_scene.cpp 코드를 std::vector, glm::vec3 등 타입을 적극 활용하여 현대 C++ 스타일로 리팩토링하였습니다.  
과제 요구사항에 따라 모든 외부 라이브러리를 포함하여 설치가 필요하지 않도록 구성했습니다.  
지피티의 도움을 받아 참고했습니다.  
