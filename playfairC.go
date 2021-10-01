package main

import (
	"bufio"
	"fmt"
	"io/ioutil"
	"log"
	"os"
	"strings"
)

//Remove Duplicate
func RemoveIndex(s []string, index int) []string {
	copy(s[index:], s[index+1:])
	s[len(s)-1] = ""
	s = s[:len(s)-1]
	return s
}

func keyMaker(textKey string) [5][5]string {
	//Trim any space in key
	textKey = strings.TrimSuffix(textKey, "\n")
	textKey = strings.ReplaceAll(textKey, " ", "")
	//Remove duplicate alphabet
	arrKey := strings.Split(textKey, "")

	//Making key
	for i := 0; i < len(arrKey); i++ {
		for j := len(arrKey) - 1; j > i; j-- {
			if arrKey[i] == arrKey[j] {
				arrKey[j] = "xx"
			}
		}
	}
	i := len(arrKey) - 1
	for i != 0 {
		if arrKey[i] == "xx" {
			arrKey = RemoveIndex(arrKey, i)
		}
		i--
	}
	//Append alphabet
	checkEmpty := true
	for al := 'a'; al <= 'z'; al++ {
		kataAddon := string(al)
		for i := 0; i < len(arrKey); i++ {
			if kataAddon == arrKey[i] {
				checkEmpty = false
				break
			} else {
				checkEmpty = true
			}
		}
		if checkEmpty {
			arrKey = append(arrKey, kataAddon)
		}
	}
	keepNum := len(arrKey) - 1
	for keepNum >= 0 {
		if arrKey[keepNum] == "j" {
			arrKey = RemoveIndex(arrKey, keepNum)
		}
		keepNum--

	}

	//array
	fmt.Println(len(arrKey))
	var keyM [5][5]string
	k := 0
	for i := 0; i < 5; i++ {
		for j := 0; j < 5; j++ {
			keyM[i][j] = arrKey[k]
			k++
		}
	}

	//print matriks
	for i := 0; i < 5; i++ {
		for j := 0; j < 5; j++ {
			fmt.Print(keyM[i][j], "\t")
		}
		fmt.Println()
	}

	return keyM
}

//read file plaintext
func readFileplaintext(fileName string) string {
	content, err := ioutil.ReadFile(fileName)
	if err != nil {
		log.Fatal(err)
	}
	return string(content)
}

func writeFile(encrypted []string, nameF string) {
	var sliceC []string
	for i := 0; i < len(encrypted); i += 2 {
		bigram := encrypted[i] + encrypted[i+1]
		sliceC = append(sliceC, bigram)
	}
	fmt.Println(sliceC)
	w, err := os.Create(nameF)
	if err != nil {
		log.Fatal(err)
	}
	defer w.Close()
	for _, sliceC := range sliceC {
		_, err := w.WriteString(sliceC + " ")

		if err != nil {
			log.Fatal((err))
		}
	}
	fmt.Println("New text created !")
}

func plaintextProce(plaintext string) []string {
	//Trim any space in key
	plaintext = strings.TrimSuffix(plaintext, "\n")
	plaintext = strings.ReplaceAll(plaintext, " ", "")
	plaintext = strings.ReplaceAll(plaintext, "j", "i")
	//Remove duplicate alphabet
	text := strings.Split(plaintext, "")

	i := len(text) - 1
	// var textTemp []string
	for i != 0 {
		if text[i] == text[i-1] && i >= 1 {
			text = append(text, "0")
			copy(text[i:], text[i-1:])
			text[i] = "x"
		}
		i--
	}
	if len(text)%2 != 0 {
		text = append(text, "x")
	}
	return text
}

func encrypt(keyM [5][5]string, plaintextProc []string) []string {
	//key
	tempI := 0
	tempJ := 0
	var keyF []string
	k := 0
	for k < len(plaintextProc) {
		for i := 0; i < 5; i++ {
			for j := 0; j < 5; j++ {
				if plaintextProc[k] == keyM[i][j] {
					if k%2 != 0 {
						if tempJ == j {
							keyF = append(keyF, keyM[tempI+1][j])
							if i+1 < 5 {
								keyF = append(keyF, keyM[i+1][j])
							} else {
								keyF = append(keyF, keyM[0][j])
							}
						} else if tempI == i {
							keyF = append(keyF, keyM[i][tempJ+1])
							if j+1 < 5 {
								keyF = append(keyF, keyM[i][j+1])
							} else {
								keyF = append(keyF, keyM[i][0])
							}
						} else {
							keyF = append(keyF, keyM[tempI][j])
							keyF = append(keyF, keyM[i][tempJ])
						}
					} else {
						tempI = i
						tempJ = j
					}
					break
				}
			}
		}
		k++

	}

	return keyF
}

//decrypt
func decrypt(keyM [5][5]string, plaintextProcs string) []string {
	plaintextProcs = strings.TrimSuffix(plaintextProcs, "\n")
	plaintextProcs = strings.ReplaceAll(plaintextProcs, " ", "")
	//Remove duplicate alphabet
	plaintextProc := strings.Split(plaintextProcs, "")
	//key
	tempI := 0
	tempJ := 0
	var keyF []string
	k := 0
	for k < len(plaintextProc) {
		for i := 0; i < 5; i++ {
			for j := 0; j < 5; j++ {
				if plaintextProc[k] == keyM[i][j] {
					if k%2 != 0 {
						if tempJ == j {
							keyF = append(keyF, keyM[tempI-1][j])
							if i-1 >= 0 {
								keyF = append(keyF, keyM[i-1][j])
							} else {
								keyF = append(keyF, keyM[4][j])
							}
						} else if tempI == i {
							keyF = append(keyF, keyM[i][tempJ-1])
							if j-1 >= 0 {
								keyF = append(keyF, keyM[i][j-1])
							} else {
								keyF = append(keyF, keyM[i][4])
							}
						} else {
							keyF = append(keyF, keyM[tempI][j])
							keyF = append(keyF, keyM[i][tempJ])
						}
					} else {
						tempI = i
						tempJ = j
					}
					break
				}
			}
		}
		k++

	}

	return keyF
}

func main() {
	//get key
	fmt.Println("Key : ")
	key := bufio.NewReader(os.Stdin)
	textKey, _ := key.ReadString('\n')
	// fmt.Println(textKey)
	keyFi := keyMaker(textKey)

	//read file txt
	fmt.Println("Isi file plaintext.txt :")
	plaintext := readFileplaintext("plaintext.txt")
	fmt.Println(plaintext)

	//process plaintext
	plaintextProc := plaintextProce(plaintext)
	fmt.Println(plaintextProc)

	//encript process
	encrypted := encrypt(keyFi, plaintextProc)
	fmt.Println(encrypted)

	//create and write file
	writeFile(encrypted, "cipher.txt")

	//decrypt process
	cipherD := readFileplaintext("cipher.txt")
	decrypted := decrypt(keyFi, cipherD)
	fmt.Println(decrypted)
	//create and write file
	writeFile(decrypted, "decrypted.txt")
}
