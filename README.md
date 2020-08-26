# Mini Terminal
C언어로 리눅스 명령어를 실행하는 프로그램

## 명령어 정리

1. cd
 
   -cd [이동할 디렉토리명]을 입력하면 그 디렉토리로 이동합니다.
   
   -현재 경로에 없는 디렉토리명을 입력하면 아무 동작도 하지 않습니다.
  
2. ls 
 
   -현재 디렉토리의 파일명/폴더명을 화면에 나타내줍니다.
 
   -잘못 된 디렉토리라면 화면에 아무것도 띄우지 않습니다.
 
3. cp 
 
   -cp [복사할 소스파일명] [복사되는 폴더의 경로] 또는 cp [복사할 소스 파일의 경로] [복사되는 폴더의 경로] 를 입력하면 똑같은 파일이 복사됩니다.
 
   -잘못 된 파일 경로일 시 아무 동작도 하지 않습니다.
 
4. mkdir
 
    -mkdir [생성할 디렉토리명 ]을 입력하면 현재경로에서 빈 디렉토리가 생성됩니다.
  
    -이미 있는 디렉토리명과 겹치면 아무것도 생성하지 않습니다.
 
5. rmdir
  
    -rmdir [제거할 디렉토리명 ]을 입력하면 현재경로에서 디렉토리명을 확인하고 제거합니다.
  
    -현재경로에 없는 디렉토리명을 입력하면 아무동작도 하지 않습니다.
 
 6. rm
    -rm [제거할 디렉토리명]을 입력하면 현재경로에 존재하는 디렉토리인지 확인 후 디렉토리 안에 있는 파일까지 한번에 제거합니다.
 

 ## CdCheck함수 동작 설명

 1. command가 cd라면 CdCheck함수를 호출해 path를 입력받고 두가지의 경우로 나눕니다.

  - path가 "이동하려는 폴더명" 일 때

    -path가 현재 디렉토리에 있는 폴더명이 맞는지 확인 후 맞으면 그 경로로 이동합니다.

    -path가 현재 디렉토리에 있는 폴더명이 아니라면 경로를 이동하지 않습니다.
   
![디렉토리 이동](https://user-images.githubusercontent.com/66424045/90889506-473d9e00-e3f3-11ea-86b1-5ec4e29ded84.PNG "디렉토리 이동")




  - path가 ".."일때
  
     -현재 경로에서 한 단계 위의 상위 디렉토리로 경로를 이동합니다.
 
![상위디렉으로이동](https://user-images.githubusercontent.com/66424045/90889671-89ff7600-e3f3-11ea-95b8-ad1398d8276b.PNG "")

<!--stackedit_data:
eyJoaXN0b3J5IjpbMTEwOTIzOTU3OCwtMTM3MzY5NTE0MF19
-->