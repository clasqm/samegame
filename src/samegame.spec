Name:		samegame
Version:	1.1.1
Release:	1%{?dist}
Summary:	Qt implementation of SameGame.
Group:		Amusements/Games
License:	GPLv3
URL:		http://samegame.sourceforge.net/
Source0:	%{name}-%{version}.tar.gz

BuildRequires:	desktop-file-utils qt-devel >= 4.7
Requires:	qt >= 4.7

%description
Qt implementation of SameGame.

%prep
%setup -q

%build
qmake-qt4 . PREFIX=%{_prefix} VERSION=%{version}
make %{?_smp_mflags}

%install
rm -rf %{buildroot}
make install INSTALL_ROOT=%{buildroot}
desktop-file-validate %{buildroot}/%{_datadir}/applications/samegame.desktop

%clean
rm -rf %{buildroot}

%files
%defattr(-,root,root,-)
%doc gpl.txt readme.txt
%{_bindir}/*
%{_datadir}/applications/samegame.desktop
%{_datadir}/icons/hicolor/scalable/apps/samegame.svg

%post
touch --no-create %{_datadir}/icons/hicolor &>/dev/null || :

%postun
if [ $1 -eq 0 ] ; then
    touch --no-create %{_datadir}/icons/hicolor &>/dev/null
    gtk-update-icon-cache %{_datadir}/icons/hicolor &>/dev/null || :
fi

%posttrans
gtk-update-icon-cache %{_datadir}/icons/hicolor &>/dev/null || :
