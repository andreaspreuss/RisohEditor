﻿(한국어)
/////////////////////////////////////////////////////
katahiromz가 개발한 RisohEditor
/////////////////////////////////////////////////////

RisohEditor는 Win32 개발을 위한 무료 리소스 편집기입니다.
RC/RES/EXE/DLL 파일의 리소스 데이터를 편집/추출/복제/삭제
할 수 있습니다.

바이너리 다운로드: https://katahiromz.web.fc2.com/re/en

Windows XP/2003/Vista/7/8.1/10 및 ReactOS에서 작동합니다.

저작권 및 라이센스 계약에 대한 자세한 내용은 
"LICENSE.txt"를 참조하십시오.

/////////////////////////////////////////////////////

질문 1. "Risoh"가 무엇입니까?

    대답. "Risoh"라는 단어는 일본어로 "이상적인"을 의미합니다.

질문 2. edt1, edt2, cmb1은 무엇입니까?

    대답. 이들은 <dlgs.h>에 정의된 표준 제어 ID 매크로입니다.

질문 3. mcdx란 무엇입니까?

    대답. 제가 만든 특별한 메시지 컴파일러입니다.
            자세한 내용은 mcdx/MESSAGETABLEDX.md를 참조하십시오.

질문 4. Visual Studio로 컴파일할 때 잘못된 문자가 표시되는 이유는 무엇입니까?

    대답. MSVC의 리소스 컴파일러는 UTF-8 리소스 파일을 처리하는데 
            버그가 있습니다.

            UTF-16을 사용합니다 (그러나 UTF-16은 GNU windres에서 지원되지 않습니다).

질문 5. 설치 프로그램 없음과 휴대용 버전의 차이점은 무엇입니까?

    대답. 휴대용 버전은 레지스트리를 사용하지 않고 ini 파일을 사용합니다.

질문 6. 64비트 파일이 지원됩니까?

    대답. 예. 64비트 Windows에서는 가능합니다. 그러나 WoW64 에뮬레이션 레이어는 
           "C:\Program Files" 또는 C:\Windows\system32"에서 로드되는 것을 방지합니다.
            로드하기 전에 64비트 파일을 다른 위치에 복사해야 합니다.

/////////////////////////////////////////////////////
// 업데이트 내역

- v.0.6 (2017.08.31)
    - 첫번째 출시입니다.
- v.5.0.8 (2018.09.12)
    - 도구 모음 아이콘이 개선되었습니다.
    - 추출시 파일 유형이 수정되었습니다.
    - UTF-8 감지에 도움이 되도록 소스 파일에 dagger를 작성합니다.
    - 트리뷰 아이콘이 수정되었습니다.
    - RT_DIALOG 및 RT_MENU 리소스 템플릿을 언어로 분할합니다.
- v.5.0.9 (2018.09.27)
    - resource.h 출력이 개선되었습니다.
    - 트리뷰 파일 아이콘이 개선되었습니다.
    - 가져오기가 개선되었습니다.
- v.5.1.0 (2018.10.08)
    - "문자열 항목" 대화상자 (여러줄)가 개선되었습니다.
    - Ctrl+A 동작이 수정되었습니다.
    - 파일 저장시 파일 잠금을 확인합니다.
    - 리소스 ID는 대소문자를 구분합니다.
    - 리소스 항목의 인코딩을 지원합니다.
    - "언어" 대화상자에서 비정상 종료가 수정되었습니다.
- v.5.1.1 (2018.11.08)
    - 캡션 텍스트 상자에 공백을 허용합니다.
    - 언어 텍스트 상자에 공백을 허용합니다.
- v.5.1.2 (2018.12.08)
    - 창 클래스 이름 텍스트 상자에 공백을 허용합니다.
    - 창 클래스 이름 텍스트 상자에 C 문자열 리터럴을 허용합니다.
    - 템플릿 시스템이 개선되었습니다.
    - 매니페스트 템플릿을 활성화했습니다.
    - 도구 모음 UI 업데이트가 수정되었습니다.
    - "리소스 ID 목록"의 ID 유형을 올바르게 표시합니다.
    - 출력시 언어를 올바르게 정렬합니다.
- v.5.1.3 (2019.01.01)
    - "리소스 ID 목록"이 수정되었습니다.
- v.5.1.4 (2019.01.13)
    - 영어 설치 프로그램을 추가했습니다.
    - 이탈리아어 설치 프로그램을 추가했습니다.
    - 이탈리아어 번역을 추가했습니다.
    - 일부 언어 설치 프로그램을 추가했습니다.
- v.5.1.5 (2019.01.27)
    - WS_EX_MDICHILD 확장 스타일을 사용하지 않습니다.
    - ReactOS를 지원합니다.
- v.5.1.6 (2019.02.24)
    - 이탈리아어 번역이 개선되었습니다.
    - GUI 조정입니다.
    - "새 언어로 복제"가 수정되었습니다.
- v.5.1.7 (2019.03.20)
    - PBS_MARQUEE 및 PBS_SMOOTHREVERSE 스타일을 추가했습니다.
    - 컴파일 오류 프로세스가 수정되었습니다.
- v.5.1.8 (2019.05.14)
    - 복제시 재컴파일 검사를 추가합니다.
    - 복제 후 선택 사항이 수정되었습니다.
    - 문자열 테이블 및 메시지 테이블의 컴파일 오류시 올바르게 실패합니다.
- v.5.1.9 (2019.07.14)
    - 지원되는 UTF-16 소스 입력/출력입니다.
- v.5.2.0 (2019.07.26)
    - DIALOG STYLE 값을 올바르게 처리합니다 (WS_CAPTION은 DIALOG STYLE의 기본값 임).
    - 확장하지 않고 압축된 EXE 파일을 열 때 응용 프로그램이 예기치 않게 파일을 삭제하는 버그가 수정되었습니다.
- v.5.2.1 (2019.08.04)
    - 언어 이름에 "En"을 입력하면 "영어 (미국)"가 선택됩니다.
    - "쿼리 상수" 기능을 추가했습니다.
    - "모두 축소"가 수정되었습니다.
    - WS_POPUPWINDOW | WS_BORDER는 WS_POPUPWINDOW | WS_CAPTION여야 합니다.
    - RT_FONT 지원합니다.
    - "리소스 추가" 대화 상자가 개선되었습니다.
- v.5.2.2 (2019.08.14)
    - 이탈리아어 번역이 업데이트되었습니다.
    - XML, XSLT, SCHEMA 및 REGISTRY 리소스 유형을 지원합니다.
    - RT_ICON/RT_CURSOR 및 RT_GROUP_ICON/RT_GROUP_CURSOR의 언어 불일치시 해석이 개선되었습니다.
    - RT_DLGINIT 및 RT_DIALOG의 언어 불일치시 해석이 개선되었습니다.
- v.5.2.3 (2019.09.14)
    - AUTORADIOBUTTON STYLE이 수정되었습니다.
- v.5.2.4 (2019.09.15)
    - XP를 지원합니다.
- v.5.2.5 (2019.09.19)
    - 대화 상자 스타일 목록 상자의 WS_CHILDWINDOW 버그가 수정되었습니다.
    - 릴리스 파일 이름 (RisohEditor-X.X.X.exe 및 RisohEditor-X.X.X.zip)이 변경되었습니다.
    - TRANSLATORS.txt가 추가되었습니다.
    - 소유자가 그린 제어를 볼 수 있게 만들었습니다.
- v.5.2.6 (2019.09.23)
    - 언어 대화 상자가 개선되었습니다.
    - 러시아어 번역을 추가했습니다.
    - 설치된 위치에 공백 문자가 있는 경우 오류 메시지를 표시합니다.
    - popen 문제를 해결하기 위해 windres 호출에 --use-temp-file 옵션을 추가했습니다.
- v.5.2.7 (2019.10.20)
    - 언어 대화 상자가 다시 개선되었습니다.
    - 대화 항목 표시의 위치가 수정되었습니다.
- v.5.2.8 (2020.01.30)
    - 러시아어 번역을 수정합니다.
    - 정의되지 않은 컨트롤을 표시할 수 있습니다.
    - "BEGIN/END 사용" 옵션이 추가되었습니다.
    - DLL을 다른 이름으로 저장할 수 없는 버그가 수정되었습니다.
- v.5.2.9 (2020.02.01)
    - 5.2.8의 XP 지원은 잊혀집니다. 이제 활성화되었습니다.
    - 파일 저장 처리가 수정되었습니다.
    - 사용자 소유의 실행 파일없이 EXE/DLL 파일을 저장할 수 있습니다.
    - 백업 방법이 수정되었습니다.
- v.5.3.0 (2020.02.06)
    - 일부 텍스트 상자에 ES_AUTOHSCROLL을 추가했습니다.
    - 파일 덮어쓰기시 논리적 오류가 수정되었습니다.
- v.5.3.1 (2020.02.23)
    - 메뉴 리소스 읽기/표시가 수정되고 개선되었습니다.
    - IDC_STATIC 처리 기능이 개선되었습니다.
    - "리소스 ID 목록" 창이 개선되었습니다.
- v.5.3.2 (2020.03.02)
    - 위치 조회없이 Ctrl+S로 저장할 수 있습니다.
    - "RC 파일을 UTF-16으로 출력" 옵션을 비휘발성으로 설정했습니다.
    - "리소스 ID의 목록" 창을 맨 위로 가져옵니다.
- v.5.3.3 (2020.03.03)
    - 파일 크기를 9MB에서 3MB로 줄였습니다.
- v.5.3.4 (2020.03.19)
    - 도구모음 저장 버튼 동작이 변경되었습니다.
    - 프로그래밍 언어 EGA를 사용하여 자동화를 도입했습니다.
    - 파일 변경 사항 저장 확인을 추가했습니다.
- v.5.3.5 (2020.03.26)
    - 이탈리아어 번역이 개선되었습니다.
    - 불필요한 저장 확인이 수정되었습니다.
- v.5.3.6 (2020.04.15)
    - 루프 변수를 32비트로 변경하면 무한 루프를 피할 수 있습니다.
    - Delphi DFM 데이터를 지원합니다.
    - 상황에 맞는 메뉴가 개선되었습니다.
- v.5.3.7 (2020.04.28)
    - 파일 끌기시 파일 변경 플래그가 업데이트되었습니다.
    - 압축 해제시 파일 이름이 개선되었습니다.
    - EGA가 강화되었습니다.
    - 러시아어 번역이 개선되었습니다.
- v.5.3.8 (2020.05.22)
    - "자동화" 메뉴에 "EGA 수동 열기" 항목이 추가되었습니다.
    - 파일 변경 플래그를 엄격하게 제어했습니다.
- v.5.3.9 (2020.06.01)
    - "대화 대화 글꼴 바꾸기" 기능이 추가되었습니다.
    - 일부 메뉴 항목을 "편집" 메뉴로 이동했습니다.
    - 리소스 이름 및 리소스 유형에 대한 0값 검사를 추가했습니다.
    - 샘플 리소스 대화 상자에 DS_CENTER 스타일을 추가했습니다.
    - F1, F3, F5 및 F6 기능 키를 활성화했습니다.
    - 휴대용 버전이 추가되었습니다.
    - 검색 기능이 개선되었습니다.
- v.5.4.0 (2020.06.13)
    - RT_ACCELERATOR 출력 (부호없는 16비트)이 수정되었습니다.
    - "res 폴더에 저장" 옵션이 제거되었습니다.
    - GUI 편집시 충돌이 수정되었습니다.
    - 추출 기능이 강화되었습니다.
    - replace-dialog-font 기능이 수정되었습니다.
    - 제목 표시줄에 전체 경로를 사용했습니다.
    - 드롭 다운 언어 화살표가 추가되었습니다.
    - "쿼리 상수" 대화상자가 수정되었습니다.
    - "리소스 항목 인코딩" 대화상자가 수정되었습니다.
    - "ID 연결" 대화상자가 개선되었습니다.
    - "미리 정의된 매크로" 대화상자가 개선되었습니다.
    - "구성" 대화상자가 개선되었습니다.
    - "검색"대화상자가 수정되었습니다.
    - 상태 메시지가 개선되었습니다.
    - 플래그 처리가 개선되었습니다.
- v.5.4.1 (2020.06.14)
    - 두 번째 덮어쓰기 저장이 실패하는 버그가 수정되었습니다.
    - 제목 표시줄 텍스트가 수정되었습니다.
    - 상태 표시줄 메시지가 수정되었습니다.
    - 독일어 번역이 추가되었습니다.
    - 프랑스어 번역이 추가되었습니다.
- v.5.4.2 (2020.06.18)
    - "코드 편집기" 또는 "Hex 뷰어"를 선택할 수 있는 탭 컨트롤이 추가되었습니다.
    - 독일어 및 프랑스어 번역이 개선되었습니다.
    - 언어 드롭 다운 화살표가 수정되었습니다.
    - 유니코드 인코딩 처리가 수정되었습니다.
    - 내보내기 및 추출 기능이 개선되었습니다.
    - EGA 대화상자가 개선되었습니다.
- v.5.4.3 (2020.07.03)
    - 추출 파일 이름이 개선되었습니다.
    - 리소스 이름/언어 변경시 트리뷰 항목을 정렬합니다.
    - 아이콘/커서 추출이 개선되었습니다.
    - 인코딩된 텍스트의 개행 코드가 개선되었습니다.
    - "리소스 추가" 대화 상자가 수정되었습니다.
    - HTML/Manifest를 가져올 수 있게 되었습니다.
    - "도움말" 메뉴에 업데이트 확인 기능이 추가되었습니다.
    - 메시지 상자 제목이 수정되었습니다.
    - 글자 수 제한을 완화하고 대용량 데이터를 지원합니다
    - 파일을 저장할 때 체크섬을 0으로 재설정합니다.
- v.5.4.4 (2020.07.09)
    - 사용하기 전에 파일 내용을 비웁니다.
    - 국제 Delphi DFM 데이터를 지원합니다.
    - "Delphi DFM 설정" 메뉴 항목을 "편집" 메뉴에 삽입했습니다.
    - 파일을 저장할 때 체크섬을 0으로 올바르게 재설정합니다.
    - 컨트롤이 1픽셀 씩 이동하는 버그가 수정되었습니다.
    - 바이러스 검사를 위해 파일 저장시 대기 시간이 추가되었습니다.
    - "도움말" 메뉴에 "RisohEditor 안내서" 링크를 추가했습니다.
- v.5.4.5 (2020.08.03)
    - 인도네시아어 번역이 추가되었습니다.
    - 언어 콤보 상자에 자동 완성 기능이 추가되었습니다.
- v.5.4.6 (2020.10.03)
    - 버전 확인에서 캐시를 삭제했습니다.
    - 테스트 대화 상자 위치가 수정되었습니다.
    - RT_DLGINIT가 허가없이 사라지는 버그가 수정되었습니다.
- v.5.4.7 (2020.10.18)
    - XP 지원을 위해 Inno Setup을 5.6.1로 다운그레이드했습니다.
    - 테스트 대화 상자에서 ActiveX 창 클래스 "AtlAxWin140"을 초기 지원합니다.
- v.5.4.8 (2020.11.12)
    - 핀란드어 번역이 추가되었습니다.
    - *.rc 및 *.res 파일 연결이 추가되었습니다.
    - OLE 컨트롤의 초기 지원합니다.
    - MOleCtrl을 삭제하고 MOleHost를 추가했습니다.
    - REGINST 데이터를 지원합니다.
- v.5.4.9 (2021.01.21)
    - 트리뷰 항목의 이름을 바꿀 때 ID 목록을 새로 고칩니다.
- v.5.5.0 (2021.01.26)
    - 한국어 번역이 추가되었습니다.
- v.5.5.1 (2021.02.02)
    - windres를 2.36으로 업그레이드했습니다.
    - BITMAP 또는 OWNERDRAW의 메뉴 항목을 컴파일할 수 있습니다.
- v.5.5.2 (2021.02.27)
    - Win2k3의 텍스트 상자에서 Ctrl+A를 수정했습니다.
    - TYPELIB 리소스 유형을 처리하기 위해 tlb2idl 프로그램을 추가했습니다.
    - TYPELIB 미리보기가 지원됩니다.
    - 폴란드어 번역이 추가되었습니다.
    - 기본적으로 "menifest 문 줄바꿈" 기능을 사용할 수 없습니다.
- v.5.5.3 (2021.03.30)
    - windres.exe가 2.36.1로 업그레이드되었습니다.
    - 짧은 경로명을 사용하여 mcpp.exe 및 windres.exe의 하위 프로세스를 생성합니다.
- v.5.5.4 (2021.04.13)
    - Vista 가져오기 아이콘을 수정합니다.
- v.5.5.5 (2021.04.23)
    - tlb2idl 프로그램을 삭제했습니다.
    - TYPEELIB 리소스 유형을 처리할 OleBow 프로그램을 추가했습니다.
    - MIDL 컴파일러를 사용할 수 있는 경우 TYPEELIB를 컴파일합니다.

/////////////////////////////////////////////////////////////////////
Katayama Hirofumi MZ (katahiromz) [A.N.T.]
Webpage (English):  https://katahiromz.web.fc2.com/re/en
Webpage (Korean):   https://katahiromz.web.fc2.com/re/ko
Webpage (Chinese):  https://katahiromz.web.fc2.com/re/ch
Webpage (Japanese): https://katahiromz.web.fc2.com/re/ja
Webpage (Italian):  https://katahiromz.web.fc2.com/re/it
Webpage (Russian):  https://katahiromz.web.fc2.com/re/ru
Email               katayama.hirofumi.mz@gmail.com
/////////////////////////////////////////////////////////////////////
