from challenge_palindrome import palindrome, del_punc_space

def test_palindromes():
    assert palindrome('sagas')
    assert palindrome('Radar')
    assert palindrome('Was it a cat I saw?')
    assert palindrome('Eva, can I see bees in a cave?')
    assert palindrome('Red rum, sir, is MURDER!!')

def test_non_palindromes():
    assert palindrome("This should not not work") == False
    assert palindrome('radars') == False
