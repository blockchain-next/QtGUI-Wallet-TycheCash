**1. Clone wallet sources**

```
git clone https://github.com/blockchain-next/QtGUI-Wallet-TycheCash.git
```

**3. Set symbolic link to coin sources at the same level as `src`. For example:**

```
ln -s ../TycheCash TycheCash
```

Alternative way is to create git submodule:

```
git submodule add https://github.com/TycheCashfoundation/TycheCash.git TycheCash
```

**4. Build**

```
mkdir build && cd build && cmake .. && make
```
