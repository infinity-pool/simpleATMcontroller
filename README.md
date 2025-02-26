# simpleATMcontroller

## Requirements
At least following flow should be implemented.<br>
**Insert Card => PIN number => Select Account => See Balance/Deposit/Withdraw**

## Assumptions
1. There are only 1 dollar bills(no cents). Thus account balance can be represented in integer.
2. The length of PIN is 4.
3. The PIN of all cards is **"1234"** in this world.
4. Every card has 10 accounts with 0 balance.
5. There's at least one account in a card.
6. Every card_id is greater than 0.

## How to clone this project


## How to build, run, test and clean build file
**Every commands should be executed on root directory!!**
### Build
```bash
$ make
```

### Run
After build,
```bash
$ make run
```

### Test
After build,
```bash
$ make test
```

### Clean Build Files
```bash
$ make clean
```